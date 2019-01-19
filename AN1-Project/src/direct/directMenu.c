/*
 * directMenu.c
 *
 *  Created on: 16 nov 2018
 *      Author: Elia
 */

#include "an1.direct.h"

int* parseLinearSystem(Matrix A, Vector b);

/**
 * This function is meant to be a menu to choose between the Direct
 *  algorithms to solve the linear systems.
 *
 * @return int exit code:
 *      `0` : Correct outcome
 *      `2` : Wrong Function Choosing
 *      `3` : Wrong Method Choosing
 */

int directMenu(){
	int c, m, n;
	int ans;
	Matrix A = NULL;
	Vector b = NULL;

	int *dim;
	dim = parseLinearSystem(A, b);
	m = dim[0];
	n = dim[1];

	printf("You can choose one of the following:\n");
	printf(" - type `1` to Gaussian Elimination;\n");
	printf(" * type `2` to LU factorization;\n");
	printf(" * type `3` to LU factorization;\n");
	printf(" * type `4` to QR factorization;\n>> ");
	printf(" - type `0` to quit.\n\n");
	scanf("%d", &c);
	printf("\n\n");


	switch (c) {
	case 1:
		ans = gaussianSolution(A, b, m, n);
		int i;
		for (i = 0; i < m; i++)
			printf("%lf", b[i]);
		break;

	case 0:
		printf("Aborted\n");
		break;

	default:
		return 3;
	}

	return 0;
}

int* parseLinearSystem(Matrix A, Vector b){
	int i, j, m, n, *ret;
	FILE *fileP;
	int choice;
	double x, min, y;
	ret = malloc(sizeof(int)*2);

	printf("You can choose one of the following to parse a matrix:\n");
	printf(" - type `1` to parse the default system `source/GaussDefaultSystem.txt`;");
	printf(" - type `2` to parse a `.txt` file;\n");
	printf(" - type `3` to parse a random system;\n");
	printf(" - type `4` to parse a system manually (discouraged);");
	choice = scanInt(1, 4);

	if (choice == 1 || choice == 2){
		// Default Source
		if (choice == 1)
			fileP = fopen("source/GaussElimMatrix.txt", "r");
		// Particular Source
		else{
			char filepath[256];
			printf("Please specify a file-path.\n>> ");
			fgets(filepath, 256, stdin);
			fileP = fopen(filepath, "r");
		}

		// Scann the Source
		fscanf(fileP, "%d %d", &m, &n);
		A = allocMatrix(m, n);
		b = allocVector(m);
		int np = n + 1;

		for (i=0; i<m*np; i++){
			fscanf(fileP, "%lf", &x);
			if (i%np == n)
				b[i/np] = x;
			else
				A[i/np][i%np] = x;
		}
		// Manual Scan
	} else {
		printf("Insert the number of equations:\n");
		m = scanInt(1, 100);
		printf("Insert the number of unknowns:\n");
		n = scanInt(1, 100);

		A = allocMatrix(m, n);
		b = allocVector(m);

		// Random Scan
		if (choice == 3){
			printf("Insert minimum and maximum values for your system value range:\n>> ");
			scanf("%lf %lf", &min, &y);
			for (i = 0; i < m; i++){
				for (j = 0; j < n; j++){
					A[i][j] = Random(min, y);
				}
				b[i] = Random(min, y);
			}
			// Manual Scan
		} else {
			for (i = 0; i < m; i++){
				printf("Insert the coefficient list for the %d-th equation and its known term:\n>> ", (i+1));
				for (j = 0; j < m; j++)
					scanf("%lf", &A[i][j]);
				scanf("%lf", &b[i]);
			}
		}
	}

	ret[0] = m;
	ret[1] = n;

	return ret;
}
/*
	int i, n=0;
	double x;
	int choice;
	double **mat;
	FILE *fileP;

	printf("Do you want to parse Default File:\n");
	printf("\t`source/GaussElimMatrix.txt`? (1=yes/0=no)");
	scanf("%d", &choice);

	if (choice == 1) {
		fileP = fopen("source/GaussElimMatrix.txt", "r");
		fscanf(fileP, "%d", &n);
		mat = allocQMatrix(n);

		for (i=0; i<n*n; i++){
			fscanf(fileP, "%lf", &x);
			mat[i/n][i%n] = x;
		}
	} else {
		printf("Insert the Matrix Dimension: ");
		scanf("%d", &n);

		mat = parseQMatrix(n);
	}

	np[0] = n;                                                                  ////??

	printf("\n======Data Reading Complete======\n\n");

	printf("n = %d\n", *np);
	printf("Matrix A has been parsed in:\n");
	printQMatrix(*np, mat);
	return mat;
 */
