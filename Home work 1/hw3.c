#include <stdio.h>
#define N 3

int main(void)
{
    int matrix[N][N],number = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            number++;
            matrix[i][j] = number;
            if(i+j+1<N)
            { 
                matrix[i][j] = 0;
            }
            else
            {                
                matrix[i][j] = 1; 
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            //printf("matrix[%d][%d]",i,j);
            printf("%d ",matrix[i][j]);
        }
        printf(" \n");
    }
}