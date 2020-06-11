**Heated Plate Parallel Implementation**

This program variation contains:

> :white_check_mark: #pragma omp for
> :white_check_mark: #pragma omp for reduction(+ : mean)
> :white_check_mark: #pragma omp parallel shared(mean, w) 
> :white_check_mark: #pragma omp critical

