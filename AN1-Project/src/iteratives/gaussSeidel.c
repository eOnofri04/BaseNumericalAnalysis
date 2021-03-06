/*
 * gaussSeidel.c
 *
 *  Created on: 30 gen 2019
 *      Author: Elia Onofri
 **
 *	Macros used:
 *	 fprintPoint(p, x, fx) -> fprintf(p, ""flfpf" "flfpf"\n", x, fx)
 *	 Matrix -> double**
 *	 Vector -> double*
 */


#include "an1.iteratives.h"

int gaussSeidel(Matrix A, Vector b, int n, Vector x, double err, int p);


/** gaussSeidel ***********************************************************
 *
 *	This method evaluates the solution of a linear system updating the
 *	 solution `x^{(k)}` in:
 *	```math
 *	x^{(k+1)}[i] = c[i] - B[i] * x^{(k)}
 *	```
 *	where
 *	```math
 *	c[i] = b[i]/A[i][i]
 *	```
 *	and
 *	```math
 *	C[i][j] =
 *	\begin{cases}
 *		B[i][j] / B[i][i]	&	\mbox{if } i \ne j\\
 *		0					&	\mbox{otherwise}
 *	\end{cases}
 *	```
 *
 *	The method continues until the error (evaluated in `p`-norm)
 *	 is smaller than `err`.
 *
 *	The method also print the sequence of normas found on a file called:
 *	 `results/iteratives/gaussSeidel.txt`
 *
 *	@param A Matrix: the coefficient matrix.
 *	@param b Vector: the known term vector.
 *	@param n int: the dimension of the matrix and of the vector.
 *	@param x Vector: the unknown terms vector.
 *	@param err double: max error range.
 *	@param p int: norm counter.
 *
 *	@return int: exit-code:
 *	  `0` : success.
 *	  `1` : zero values on the matrix diagonal.
 *	  `2` : iteration number have overflow (no solution found).
 *
 *************************************************************************/

int gaussSeidel(Matrix A, Vector b, int n, Vector x, double err, int p){
	int i, j, counter;  // counters
	double k;           // iteration
	double temp;        // temp / accumulator
	Matrix Bgs = NULL;  // updating matrix
	Vector cgs = NULL;  // updating vector
	double norm;        // error norm
	FILE *fileP;        // output file pointer

	fileP = fopen("results/iteratives/gaussSeidel.txt", "w");

	if (fileP == NULL) {
		printf("ERROR: can't open `results/systems/gaussSeidel.txt` in writing mode.\n");
		exit(1);
	}


	cgs = allocVector(n);
	Bgs = copyMatrix(A, n, n);

	// Basis Construction
	for (i = 0; i < n; i++){
		if (A[i][i] == 0.0){
			free(cgs);
			return 1;
		}
		temp = A[i][i];
		for (j = 0; j < n; j++)
			Bgs[i][j] = A[i][j] / temp;
		cgs[i] = b[i] / temp;
	}

	counter = 0;
	norm = evalSystemError(A, x, b, n, n, p);
	while (norm > err && counter < MAX_ATTEMPTs){
		k = counter / n;
		j = counter % n;
		fprintPoint(fileP, (double)counter / n, norm);

		// updating
		temp = cgs[j];
		for (i = 0; i < j; i++)
			temp = temp - Bgs[j][i] * x[i];
		for (i = j+1; i < n; i++)
			temp = temp - Bgs[j][i] * x[i];
		x[j] = temp;

		norm = evalSystemError(A, x, b, n, n, p);
		counter++;
	}

	fprintPoint(fileP, (double)counter / n, norm);

	fclose(fileP);
	free(Bgs);
	free(cgs);

	if (counter >= MAX_ATTEMPTs){
		return 2;
	}

	printf("The solution was found in %d iterations.\n", counter);

	return 0;
}
