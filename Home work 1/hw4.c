#include <stdio.h>
#define N 5
int main(void)
{
    //int N;
    //scanf("%d",&N);
    int matrix[N][N],number = 0,k = 0,m = 0,nn = N-1,step = 0;
    for(int i = 0; i < N; i++ )
    {
        number++;
        matrix[0][i] = number;
    }
    while(N*N > number)
    {
        for(int i = 1; i < N-step; i++ )
        {
            k++;
            number++;
            matrix[k][nn] = number;
        }
        for(int j = 1; j < N-step; j++ )
        {
            nn--;
            number++;
            matrix[k][nn] = number;
        }
        // break;
         step++;
        for(int j = 1; j < N-step; j++ )
        {
            k--;
            number++;
            matrix[k][nn] = number;
        }
        for(int j = 1; j < N-k-m; j++ )
        {
            nn++;
            number++;
            matrix[k][nn] = number;
        }
        step++;
        m++;
        // break;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            //printf("matrix[%d][%d]",i,j);
            printf("%5d",matrix[i][j]);
        }
        printf(" \n");
    }
}