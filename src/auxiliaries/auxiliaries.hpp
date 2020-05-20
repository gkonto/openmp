#ifndef AUXILIARIES_HPP
#define AUXILIARIES_HPP

#include <sstream>

template<typename T>
extern void read_value(char *arg, T &val) {
    std::stringstream ss;
    ss << arg;
    ss >> val;
}


extern void initialize_rand_arr(unsigned char *arr, size_t size);
extern long long int accumulate(unsigned char *arr, size_t size);
extern void timestamp();
extern double dist(int nd, double r1[], double r2[], double dr[]);
extern void timestamp();

#endif
