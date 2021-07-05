#include "libmycalculator.h"

void division()
{
    calculator.variable1;
    calculator.variable2;
    calculator.answer;
    printf("variable 1:");
    scanf("%d",&calculator.variable1);
    printf("variable 1:");
    scanf("%d",&calculator.variable2);
        if(calculator.variable2!= 0 )
        {
        calculator.answer = calculator.variable1 / calculator.variable2;
        printf("Answer = %d\n",calculator.answer);
        }
        else { 
            printf("You cannot divide by zero!\n");
        }
   
}