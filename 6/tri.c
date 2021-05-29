#include <stdio.h>
#include <stdlib.h>

// calloc array 2D =======================================================
int** callocArray2D(int r, int c)
{
    int **A = (int **)malloc((unsigned int)r*sizeof(int *));
    for (int i = 0; i < r; i++)
        A[i] = (int *)calloc((unsigned int)c, sizeof(int));

    return A;
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

int cntMonochromaticTriangles(int **A, int n)
{
    int i, j, k, cnt=0;
    for (i = 0; i < n; i++)
        for (j = i+1; j < n; j++)
            for (k = j+1; k < n; k++)
                if (A[i][j] == A[i][k] && A[i][j] == A[j][k])
                    cnt++;

    return cnt;
}

int main()
{
    int n, m, p, q;
    scanf("%d %d", &n, &m);

    // A[i][j] - kolor odcinka miedzy wierzcholkiem i-tym i j-tym
    // 0 - czarny
    // 1 - czerwony
    int **A = callocArray2D(n, n);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &p, &q);
        A[p-1][q-1] = 1;
    }

    int cnt = cntMonochromaticTriangles(A, n);
    printf("%d", cnt);

    freeArray2D(A, n);

    return 0;
}
