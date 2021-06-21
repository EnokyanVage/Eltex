#include <stdio.h>
#define N 3

int main(void)
{
    int matrix[N][N],number = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            number++;
            matrix[i][j] = number;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }
}

/*
  1  2  3
  4  5  6
  7  8  9
*/
