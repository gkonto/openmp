#include <math.h>
#include <stdio.h>
#include "common.hpp"

void generate_list(int *x, int n) {
  for (int i = 0; i < n; i++)
    x[i] = i;
  for (int i = 0; i < n; i++) {
    int j = rand() % n;
    int t = x[i];
    x[i] = x[j];
    x[j] = t;
  }
}

void print_list(int *x, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", x[i]);
  }
}

