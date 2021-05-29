#include <stdio.h>
#include <stdlib.h>

// free array 2D =========================================================
void freeArray2D(int **A, int n)
{
    for (int i = 0; i < n; i++)
        free(A[i]);
    free(A);
}
//========================================================================

int** generateMatrixOfSums(int **F, unsigned int n, int r)
{
    int **matrixOfSums = (int **)malloc(n*sizeof(int *));
    for (int i = 0; i < n; i++)
        matrixOfSums[i] = (int *)calloc(n, sizeof(int));

    int i1, j1, i2, j2;
    for (i1 = 0; i1 < n; i1++)
        for (j1 = 0; j1 < n; j1++)
            for (i2 = i1-r; i2 <= i1+r; i2++)
                for (j2 = j1-r; j2 <= j1+r; j2++)
                    if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < n)
                        matrixOfSums[i1][j1] += F[i2][j2];

    return matrixOfSums;
}

void printArray2D(int **A, unsigned int r, unsigned int c)
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
    unsigned int n;
    int r;
    scanf("%d %d", &n, &r);

    int **F = (int **)malloc(n*sizeof(int *));
    for (int i = 0; i < n; i++)
        F[i] = (int *)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &F[i][j]);

    int **W = generateMatrixOfSums(F, n, r);
    printArray2D(W, n, n);

    freeArray2D(F, (int)n);
    freeArray2D(W, (int)n);

    return 0;
}
