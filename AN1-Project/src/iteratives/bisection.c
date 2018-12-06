//
//  bisection.c
//  ProjectManager
//
//  Created by Elia Onofri on 13/11/18.
//  Copyright © 2018 Elia Onofri. All rights reserved.
//

#include "an1.iteratives.h"

double exeBisection(double (*f)(double));

/**
 * Bisection method is a Iterative method to compute the zero of a given
 *  function `f`. To do so, it needs a left `a` and a right `b` element to start from.
 *
 * @param a double: left margin;
 * @param b double: right margin;
 * @param e double: approx error needed;
 * @param f double *(double): pointer to the function.
 *
 * @return ans: the zero found by the method.
 */
double bisection(double a, double b, double e, double (*f)(double)){
    double c = a;
    int counter = 0;

    if (f(a) * f(b)>=0) {
        if (f(a) == 0){
            printf("The function has a `0` in %lf", a);
            return a;
        }
        if (f(b) == 0){
            printf("The function has a `0` in %lf", b);
            return b;
        }
        printf("ERROR: f(a)*f(b) > 0!\n\n");
        return 0;
    }

    while (fabs(b-a) > e && fabs(f(c)) > e && counter < MAX_ATTEMPTs) {
        c = (a+b)/2;
        if (f(a)*f(c) > 0) a = c;
        else b = c;
        counter++;
    }
    if (counter >= MAX_ATTEMPTs) printf("No zeros where found within the first %d iterations with the required precision. The partial zero found is located at `%lf`.\n", counter, c);
    else printf("The function has a zero in `%lf` (found in %d iteration) with a maximum error of `%lf`.\n", c, counter, e);
    return c;
}

double exeBisection(double (*f)(double)){
    double a, b, e;
    printf("Type left initialization, right initialization and error: ");
    scanf("%lf %lf %lf", &a, &b, &e);
    return bisection(a, b, e, f);
}
