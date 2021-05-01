#include <stdio.h>
#include <stdlib.h>

// malloc array 2D =======================================================
int** mallocArray2D(int r, int c)
{
    int **A = (int **)malloc((unsigned int)r*sizeof(int *));
    for (int i = 0; i < r; i++)
        A[i] = (int *)malloc((unsigned int)c*sizeof(int));

    return A;
}
//========================================================================

// read into array 2D ====================================================
void readIntoArray2D(int **A, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &A[i][j]);
}
//========================================================================

int findMaxCommonFieldsSum(int **T, int **P, int n, int k, int l)
{
    int i, j, q, r, sum, maxSum=0;
    for (i = 0; i < n-k; i++)
    {
        for (j = 0; j < n-l; j++)
        {
            sum = 0;
            for (q = 0; q < k; q++)
                for (r = 0; r < l; r++)
                    if (P[q][r] == 1)
                        sum += T[i+q][j+r];

            if (sum > maxSum)
                maxSum = sum;
        }
    }

    return maxSum;
}

int main()
{
    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);

    int **T = mallocArray2D(n, n);
    int **P = mallocArray2D(k, l);
    readIntoArray2D(T, n, n);
    readIntoArray2D(P, k, l);

    int maxCommonFieldsSum = findMaxCommonFieldsSum(T, P, n, k, l);
    printf("%d", maxCommonFieldsSum);

    free(T);
    free(P);

    return 0;
}
