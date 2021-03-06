# ToDo
#### To do list for the project.

## Important



## Methods

  - Direct methods for solving linear systems
    - [ ] [Total Pivoting] Gauss Elimination
    - [ ] [ToDo] LU Factorization
      - [ ] [ToDo] Cholesky Factorization
      - [ ] [ToDo] Doolittle Factorization
    - [ ] [ToDo] QR factorization
  - Iteratives methods for solving linear systems
    - [X] Jacobi method
    - [X] Gauss-Seidel method
    - [X] SOR method
    - [X] [ToCheck] Richardson
  - Recursive methods for function zeros
    - [X] Bisection
    - [X] Chord
    - [ ] [ToDo] Muller
    - [X] Newton
    - [X] Newton Quotient
    - [X] Secantes
    - [X] Steffensen
  - Interpolation methods for function approximation over equidistant/chebyshev knots
    - [X] Lagrange interpolate
    - [X] Newton interpolate
    - [ ] [ToDo] Hermite interpolate
  - Least-square method for function approximation
    - [X] First order Least-square
    - [ ] [ToDo] Higher order Least-square
		
## Tasks

add `fclose()` and `free` in:
 - [X] `src/direct/*.c`
 - [X] `src/function-zeros/*.c`
 - [X] `src/interpolation/*.c`
 - [X] `src/iteratives/*.c`
 - [X] `src/utils/*.c`
 
Do the following:
 - [X] Knot Functions.
 - [ ] Write a simple evaluation if a matrix is positive defined.
 - [X] Build Vandermonde and Hilber Matrix.
 - [X] Check Triangular Solver
 - [X] Change error norma to `%10le`
 - [X] Find a way to change all the `%lf` into `%.15lf`
