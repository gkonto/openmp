/*
Παραδειγμα προσθεσης διανυσμάτων δεκαδικών αριθμών μικρής ακρίβειας (floats).
Η λειτουργία αυτή ονομάζεται SAXPY και κατέχει θεμελιώδη θέση σε εφαρμογές της γραμμικής αλγεβρας.

Εισαγωγή
Στο παράδειγμα SAXPY, ο λόγος του μεγέθους υπολογισμών προς το μέγεθος των δεδομένων που
τελούν υπό επεξεργασία είναι μικρός. Ως εκτότου, αποτελεί πρόβλημα περιορισμένης επεκτασιμότητας.
Παρόλα αυτά, πρόκειται για ένα χρήσιμο παράδειγμα που ανήκει στην κατηγορία προβλημάτων παραλληλοποίησης
τύπου map και των εννοιών uniform και varying parameters.

Περιγραφή του προβλήματος:
Η λειτουργία SAXPY δέχεται ως δεδομένα δυο διάνυσματα δεκαδικών αριθμών.
Το διάνυσμα πολλαπλασιάζεται με μια σταθερά a και στο αποτέλεσμα προστήθεται ένα διάνυσμα y.
Τα διανύσματα x,y πρέπει να έχουν το ίδιο μέγεθος.

Ο υπολογισμός αυτός εμφανίζεται συχνά στη γραμμική άλγεβρα, όπως για παράδειγμα στη διαγραφή σειρών
στην απαλοιφή Gauss. Το όνομα SAXPY δόθηκε από την βιβλιοθήκη BLAS ("Basic Linear Algrbra Subprograms")
για δεκαδικούς μονής ακρίβειας (floats). Ο αντίστοιχος αλγόριθμος διπλής ακρίβειας ονομάζεται 
DAXPY, ενώ για μιγαδικούς αριθμούς ονομάζεται CAXPY.

Η μαθηματική διατύπωση του SAXPY είναι:

                            y <-- a*x + y.
 
 όπου το διάνυσμα x χρησιμοποιείται ως είσοδος, το y ως είσοδος και έξοδος. Δηλαδή το αρχικό διάνυσμα y τροποποιείται.


 Εναλλακτικά, η λειουργία SAXPY μπορεί να περιγραφή ως συνάρτηση που δρα σε μεμονωμένα στοιχεία, οπως φαίνεται παρακάτω:
            δες σελίδα pdf 152 structure parallel computation k

Οι συναρτήσεις τύπου f δεχονται ως ορίσματα, δύο είδη παραμέτρων. Τις παραμέτρους όπως την a  που παραμένουν σταθερές και 
ονομάζονται uniform, οι παράμετροι που είναι μεταβλητές σε κάθε κλίση της f ονομάζονται varying. 
To μοτίβο (pattern) "map" καλεί τη συνάρτηση f τόσες φορές όσες και ο αριθμός των στοιχείων του διανύσματος.

*/
#include <iostream>
#include <time.h>
#include <omp.h>
#include <iomanip>
#include "saxpy.hpp"
#include "auxiliaries.hpp"


namespace {
    struct Opts{
        size_t size = 0;
    };
}

// template<typename T>
// extern void read_value(char *arg, T &val) {
//     std::stringstream ss;
//     ss << arg;
//     ss >> val;
// }


void parseArgs(int argc, char **argv, Opts &o) {
    if (argc != 2) {
        std::cout << "Specify array size!" << std::endl;
        exit(1);
    }

    read_value<size_t>(argv[1], o.size);
}


static void fill_random_arr(float *arr, size_t size) {
    #pragma omp parallel for
    for (size_t k = 0; k < size; ++k) {
        arr[k] = (float)(rand()) / RAND_MAX;
    }
}

static void verify(size_t size, float c, float *a, float *b, float *verification)
{
	for (int i = 0; i < size; ++i) {
		if (c * a[i] + verification[i] != b[i]) {
			std::cout << "Failed" << std::endl;
			exit(1);
		}
	}
}


int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    srand(time(nullptr));
    float c = float(rand()) / float(RAND_MAX);
    float *a = new float[o.size];
    float *verification = new float[o.size];
    float *b = new float[o.size];

    fill_random_arr(a, o.size);
    fill_random_arr(b, o.size);

#pragma omp parallel for
    for (size_t k = 0; k < o.size; ++k) {
	    verification[k] = b[k];
    }
    auto start = omp_get_wtime();
    saxpy(o.size, c, a, b);
    auto end = omp_get_wtime();

    verify(c, a, b, verification);
    // Calculating total time taken by the program.
    std::cout << "Execution Time : " << std::fixed
         << end - start << std::setprecision(5);
    std::cout << " sec " << std::endl;
   delete []a;
    delete []b;
    
    return 0;
}
