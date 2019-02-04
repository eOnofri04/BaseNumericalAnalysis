# ToDo
#### To do list for the project.

## Methods

	- Direct methods for solving linear systems
		- [Display] Gauss Elimination
		- [ToDo] LU Factorization
			- [ToDo] Cholesky Factorization
			- [ToDo] Doolittle Factorization
		- [ToDo] QR factorization
	- Iteratives methods for solving linear systems
		- [X] Jacobi method
		- [X] Gauss-Seidel method
		- [X] SOR method
		- [ToCheck] Richardson
	- Recursive methods for function zeros
		- [X] Bisection
		- [X] Chord
		- [ToDo] Muller
		- [X] Newton
		- [X] Newton Quotient
		- [X] Secantes
		- [X] Steffensen
	- Interpolation methods for function approximation over equidistant/chebyshev knots
		- [Display, change knot value acquisition] Lagrange interpolate
		- [ToDo] Newton interpolate
		- [ToDo] Hermite interpolate
	- Least-square method for function approximation
		- [ToDo] Least-square systems
		
## Tasks

add `fclose()` and `free` in:
 - [ ] `src/direct/*.c`
 - [X] `src/function-zeros/*.c`
 - [ ] `src/interpolation/*.c`
 - [X] `src/iteratives/*.c`
 - [X] `src/utils/*.c`

write a simple evaluation if a matrix is positive defined.