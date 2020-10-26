/*
Ο υπολογισμός του Mandelbrot αποτελεί ένα απλό παράδειγμα που περιγράφει πως
το map pattern μπορεί να περιλάβει ροή σειριακού ελέγχου και πως μπορέί να 
εκφραστεί με στοιχειώδεις λειτουργίες. Αποτελεί επίσης ένα καλό παράδειγμα 
υπολογισμού που μπορεί να οδηγήσει σε ανισσοροπια φορτίου.

ΠΕΡΙΓΡΑΦΗ ΠΡΟΒΛΗΜΑΤΟΣ
Το Mandelbrot σετ είναι ένα σετ σημείων στο μιγαδικό χώρο που δεν καταλήγουν 
στο άπειρο όταν η παρακάτω συνάρτηση επαναλαμβάνεται:
	
			z <-- z^2 + c


Πρακτικά είναι δύσκολο να αποδειχθεί ότι ο υπολογισμός δεν θα συγκλίνει, 
και έτσι ο υπολογισμός θα γίνει για μεγάλο αριθμό επαναλήψεων.
Μπορεί επίσης να αποδειχθεί ότι όταν ο z περάσει τον κύκλο με ακτίνα 2, 
είναι εγγυημένο ότι θα συγκλίνει.
Αν αυτό συμβεί, ο υπολογισμός μπορει να τερματιστεί νωρίς.
Στη συνέχεια μπορεί να χρησιμοποιηθεί ένας πίνακας αντιστοίχισης 
διαφορετικών τιμών με χρώματα, για την παραγωγή εικόνας.
		
			z0 = 0;
			z(k1-1) = zk^2 + c,
			count(c) = min(|zk| >= 2)


Ο υπολογισμός του Mandelbrot έχει μικρή πρακτική αξία, ωστόσο 
χρησιμοποιείται σε αυτό το map pattern, καθώς περιλαμβάνει data-dependent control flow.
This leads to load imbalance.
To mandelbrot υλοποιείται ευκολότερα με τη χρήση SPMD or tiled SIMD mechanisms, 
including load balancing and early termination of finished tiles.

Για την υλοποίηση χρησιμοποιούνται μιγαδική αριθμοί και η std::complex δομή
*/

#include <complex.h>
#include <iostream>
#include <complex>
#include "auxiliaries.hpp"


namespace {
	struct Opts {
		int row = 0;
		int col = 0;
	};
}

int mandel(std::complex<double> c, int depth)
{
	int count = 0;
	std::complex<double> z = 0;
	for (int k = 0; k < depth; k++) {
		if (abs(z) >= 2.0) {
			break;
		}
		z = z * z + c;
		count++;
	}
	return count;
}


void serial_mandel(int **p, int max_row, int max_col, int depth)
{
	for (int i = 0; i < max_row; ++i) {
		for (int j = 0; j < max_col; ++j) {
			p[i][j] = mandel(std::complex<double>(i/(max_row - 1.0) * (cxmax - cxmin), j/(max_col - 1.0) * (cymax - cxmin)), depth);
		}
	}
}

static void fill_random_arr(int **p, int row, int col)
{
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			p[i][j] = rand() / RAND_MAX;
		}
	}
}

static void parseArgs(int argc, char **argv, Opts &o) {
	if (argc != 3) {
		std::cout << "Speccify 2D array size" << std::endl;
		exit(1);
	}
	read_value<int>(argv[1], o.row);
	read_value<int>(argv[2], o.col);
}


int main(int argc, char **argv) {
	Opts o;
	parseArgs(argc, argv, o);
	srand(time(nullptr));

	int **p = new int*[o.row];
	for (int i = 0; i < o.row; ++i) {
		p[i] = new int[o.col];
	}

	fill_random_arr(p, o.row, o.col);

	for (int i = 0; i < o.row; ++i) {
		for (int j = 0; j < o.col; ++j) {
			std::cout << p[i][j] << std::endl;
		}
	}
}
