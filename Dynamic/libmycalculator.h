#ifndef LIBMYCALCULATOR_H_
#define LIBMYCALCULATOR_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct v_calculator
{
    int variable1;
    int variable2;
    int answer;
}my_calculator;

my_calculator calculator;
void addition();
void division();
void subtraction();
void multiplication();
#endif