**Molecular Dynamics calculation parallel version**

This program variation contains:
>:white_check_mark: #pragma omp parallel shared(f, nd, np, pos, vel) private(i, j, k, rij, d, d2)
>:white_check_mark: #pragma omp for reduction(+ : pe, ke)
>:white_check_mark: #pragma omp parallel shared(acc, dt, f, nd, np, pos, rmass, vel)
>:white_check_mark: #pragma omp for

