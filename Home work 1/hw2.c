#include <stdio.h>
#define N 5

int main(void)
{
    int matrix[N],number = 0; 
    
    for(int i = 0; i < N; i++)
    {
        number++;
        matrix[i] = number;
    }
    
    for(int j = 0; j < N; j++)
    {
        printf("%3d ", matrix[j]);
    }
    
    printf(" \n");
    
    for(int k = N-1; k >= 0; k--)
    {
        printf("%3d ", matrix[k]);
    }
    
    printf(" \n");
//     for(int k = 0; k < N; k++)
//     {
//         printf("%3d ", matrix[N-k-1]);        
//     }
//     printf(" \n");
}
/*
  1   2   3   4   5  
  5   4   3   2   1
*/
