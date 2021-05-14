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
#include <cstdlib>
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
//#pragma omp parallel for
    for (size_t k = 0; k < size; ++k) {
        arr[k] = (float)(rand()) / RAND_MAX;
    }
}

static void verify(size_t size, float c, float *a, float *b, float *verification)
{
	for (size_t i = 0; i < size; ++i) {
		if (abs(c * a[i] + verification[i] - b[i]) >= 1e-6) {
			std::cout << "Failed index: " << i << ". " << c * a[i] + verification[i] << " =! " << b[i] << std::endl;
			exit(1);
		}
	}
}

struct Containers
{
    explicit Containers(size_t containers_size);
    ~Containers();

    void setRandomValues();

    size_t m_size;
    float *m_a;
    float *m_verification;
    float *m_b;
};

Containers::Containers(size_t containers_size)
    : m_size(containers_size)
{
    srand(time(nullptr));
    m_a = new float[containers_size];
    m_verification = new float[containers_size];
    m_b = new float[containers_size];
}

Containers::~Containers()
{
    delete []m_a;
    delete []m_b;
    delete []m_verification;
}

void Containers::setRandomValues()
{
    fill_random_arr(m_a, m_size);
    fill_random_arr(m_b, m_size);

//#pragma omp parallel for
    for (size_t k = 0; k < m_size; ++k) {
	    m_verification[k] = m_b[k];
    }
}


int main(int argc, char **argv) {
    Opts o;
    parseArgs(argc, argv, o);

    Containers c(o.size);

    c.setRandomValues();
    float cons = float(rand()) / float(RAND_MAX);
    
    auto start = omp_get_wtime();
    saxpy(c.m_size, cons, c.m_a, c.m_b);
    auto end = omp_get_wtime();

    verify(c.m_size, cons, c.m_a, c.m_b, c.m_verification);

    std::cout << "Execution Time : " << std::fixed
         << end - start << std::setprecision(5);
    std::cout << " sec " << std::endl;
    return 0;
}
