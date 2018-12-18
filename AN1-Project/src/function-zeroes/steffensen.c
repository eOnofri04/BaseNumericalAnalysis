/*
 * steffensen.c
 *
 *  Created on: 6 dic 2018
 *      Author: Elia
 */

#include "an1.function-zeroes.h"

double exeSteffensen(double (*f)(double));

/**
 * Steffensen method is a Iterative method to compute the zero of a given
 *  function `f`. To do so, it only needs a initial point `x0`.
 *
 * <p>
 *
 * This method follows the following formula:
 * ```math
 *   g(x) = x - p(x) * f(x),    p(x) = f(x) / (f(x) - f(x - f(x)))
 * ```
 *
 * @param x double: initial point `x0`;
 * @param e double: approx error needed;
 * @param f double *(double): pointer to the function.
 *
 * @return x: the zero found by the method.
 */
double steffensen(double x, double e, double (*f)(double)){
	int counter = 0;
	double fx = f(x);
	double ffx = f(x + fx);


	while (fabs(fx) > e && ffx != fx && counter < MAX_ATTEMPTs) {
		x = x - fx * fx / (fx - ffx);
		fx = f(x);
		ffx = f(x - fx);
		counter++;
	}

	if (counter >= MAX_ATTEMPTs) printf("No zeros were found within the first %d iterations with the required precision. The partial zero found is located at `%lf`.\n", counter, x);
	else if (ffx == fx) printf("The method failed (at step %d) as f(x - f(x)) - f(x) = 0", counter);
	else printf("The function has a zero in `%lf` (found in %d iteration) with a maximum error of `%lf`.\n", x, counter, e);

	return x;
}

double exeSteffensen(double (*f)(double)){
	double x, e;

	printf("Type the starting point and the error: ");
	scanf("%lf %lf", &x, &e);

	return steffensen(x, e, f);
}

