#include <iostream>
#include <math.h>
#include "auxiliaries.hpp"

void initialize_rand_arr(unsigned char *arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        arr[i] = (unsigned char)rand() % 3;
    }
}


long long int accumulate(unsigned char *arr, size_t size) {
    long long int sum = 0.0;
    for (size_t i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}


void timestamp() {
#define TIME_SIZE 40
  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time(NULL);
  tm = localtime(&now);

  strftime(time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm);

  std::cout << time_buffer << std::endl;
#undef TIME_SIZE
}


double dist(int nd, double r1[], double r2[], double dr[]) {
  double d;
  int i;

  d = 0.0;
  for (i = 0; i < nd; i++) {
    dr[i] = r1[i] - r2[i];
    d = d + dr[i] * dr[i];
  }
  d = sqrt(d);

  return d;
}
