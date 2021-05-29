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

// free array 2D =========================================================
void freeArray2D(int **A, int n)
{
    for (int i = 0; i < n; i++)
        free(A[i]);
    free(A);
}
//========================================================================

int findMaxSum(int **T, int n, int k)
{
    int sums[4];
    int i, j, l, maxSum=0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (l = 0; l < 4; l++)
                sums[l] = 0;

            // wystarczy sprawdzic 4 przypadki, reszta jest redundantna
            //    # 0 [((i-l)+n)%n][(j+l)%n]
            //   #
            //  #
            // ####### 1 [i][(j+l)%n]
            // ##
            // # #
            // #  # 2 [(i+l)%n][(j+l)%n]
            //
            // 3 [(i+l)%n][j]

            for (l = 0; l < k; l++)
            {
                sums[0] += T[((i-l)+n)%n][(j+l)%n];
                sums[1] += T[i][(j+l)%n];
                sums[2] += T[(i+l)%n][(j+l)%n];
                sums[3] += T[(i+l)%n][j];
            }

            for (l = 0; l < 4; l++)
                if (sums[l] > maxSum)
                    maxSum = sums[l];
        }
    }

    return maxSum;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int **T = mallocArray2D(n, n);
    readIntoArray2D(T, n, n);

    int maxSum = findMaxSum(T, n, k);
    printf("%d", maxSum);

    freeArray2D(T, n);

    return 0;
}
