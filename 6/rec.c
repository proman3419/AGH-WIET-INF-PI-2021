#include <stdio.h>
#include <stdlib.h>

#define PLANE_SIZE 201

// calloc array 2D =======================================================
int** callocArray2D(int r, int c)
{
    int **A = (int **)malloc((unsigned int)r*sizeof(int *));
    for (int i = 0; i < r; i++)
        A[i] = (int *)calloc((unsigned int)c, (unsigned int)c*sizeof(int));

    return A;
}
//========================================================================

// read into array =======================================================
void readIntoArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
}
//========================================================================

int cntBlackSquares(int **A)
{
    int cnt = 0, i, j;
    for (i = 0; i < PLANE_SIZE; i++)
        for (j = 0; j < PLANE_SIZE; j++)
            cnt += A[i][j];

    return cnt;
}

// 0 - bialy, 1 - czarny
int** colorPlane(int N)
{
    int **A = callocArray2D(PLANE_SIZE, PLANE_SIZE);

    int coords[4];
    int i, j, tmp;
    for (i = 0; i < N; i++)
    {
        readIntoArray(coords, 4);
        for (j = 0; j < 4; j++)
            coords[j] += PLANE_SIZE/2;

        for (; coords[0] < coords[2]; coords[0]++)
        {
            tmp = coords[1];
            for (; coords[1] < coords[3]; coords[1]++)
            {
                A[coords[0]][coords[1]]++;
                A[coords[0]][coords[1]] %= 2;
            }
            coords[1] = tmp;
        }
    }

    return A;
}

int main()
{
    int N;
    scanf("%d", &N);

    int **A = colorPlane(N);
    int blackCnt = cntBlackSquares(A);
    printf("%d", blackCnt);

    free(A);

    return 0;
}
