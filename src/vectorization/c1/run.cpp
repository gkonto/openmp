#include <iostream>
#include <vector>
#include <omp.h>

int main(int argc, char **argv) {
    const int size = 1024;
    auto a = std::vector<float>(size);
    auto b = std::vector<float>(size);
    auto c = std::vector<float>(size);

    for (int i = 0; i < size; i++) {
        a[i] = 1.0*(i+1);
        b[i] = 2.5*(i+1);
        c[i] = 0.0;
    }

    double start = omp_get_wtime();
    for (int j=0; j<100000; ++j) {
#pragma omp simd
        for (int i=0; i<size; ++i) {
            c[i] = a[i] + b[i];
        }
    }
    std::cout << "Execution Time: " << omp_get_wtime() - start << std::endl;
    return 0;
}
