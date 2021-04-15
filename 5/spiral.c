#include <stdio.h>
#include <stdlib.h>

int** generateSpiral(int n)
{
    int **T = (int **)malloc((unsigned int)n*sizeof(int *));
    for (int i = 0; i < n; i++)
        T[i] = (int *)malloc((unsigned int)n*sizeof(int));

    int k=1, a=0, b=n-1, i;
    while (a <= b)
    {
        for (i = a; i <= b; i++)
        {
            T[a][i] = k;
            k++;
        }

        for (i = a+1; i < b; i++)
        {
            T[i][b] = k;
            k++;
        }

        for (i = b; i > a; i--)
        {
            T[b][i] = k;
            k++;
        }

        for (i = b; i > a; i--)
        {
            T[i][a] = k;
            k++;
        }

        a++;
        b--;
    }

    return T;
}

void printArray2D(int **A, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    int** T = generateSpiral(n);
    printArray2D(T, n, n);

    free(T);

    return 0;
}
