#include <stdio.h>
#include <stdlib.h>

// calloc array 1D =======================================================
int* callocArray(int N)
{
    int *A = (int *)calloc((unsigned int)N, sizeof(int));

    return A;
}
//========================================================================

// calloc array 2D =======================================================
int** callocArray2D(int r, int c)
{
    int **A = (int **)malloc((unsigned int)r*sizeof(int *));
    for (int i = 0; i < r; i++)
        A[i] = (int *)calloc((unsigned int)c, (unsigned int)c*sizeof(int));

    return A;
}
//========================================================================

// malloc array 2D =======================================================
int** mallocArray2D(int r, int c)
{
    int **A = (int **)malloc((unsigned int)r*sizeof(int *));
    for (int i = 0; i < r; i++)
        A[i] = (int *)malloc((unsigned int)c*sizeof(int));

    return A;
}
//========================================================================

int** generateDepthsArray(int **A, int n)
{
    int **D = callocArray2D(n, n);
    int i, j;

    for (j = 0; j < n; j++)
    {
        if (A[0][j] == 0)
            D[0][j] = 1;
        else
            D[0][j] = 0;
    }

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
                D[i][j] = 0;
            else
                D[i][j] = D[i-1][j] + 1;
        }
    }

    return D;
}

int findMaxSubField(int **D, int n, int *stack, int maxSubField, int row)
{
    int currSubField=0, stackLen=0, i, top;

    for (i = 0; i < n;)
    {
        if (stackLen == 0 || (D[row][stack[stackLen-1]] <= D[row][i]))
        {
            stack[stackLen] = i;
            stackLen++;
            i++;
        }
        else
        {
            top = stack[stackLen-1];
            stackLen--;

            if (stackLen == 0)
                currSubField = D[row][top]*i;
            else
                currSubField = D[row][top]*(i - stack[stackLen-1] - 1);

            if (currSubField > maxSubField)
                maxSubField = currSubField;
        }
    }

    while (stackLen > 0)
    {
        top = stack[stackLen-1];
        stackLen--;

        if (stackLen == 0)
            currSubField = D[row][top]*i;
        else
            currSubField = D[row][top]*(i - stack[stackLen-1] - 1);

        if (currSubField > maxSubField)
            maxSubField = currSubField;
    }

    return maxSubField;
}

int findMaxField(int **A, int n)
{
    int maxField=0;
    int **D = generateDepthsArray(A, n);
    int *stack = callocArray(n+1);

    for (int i = 0; i < n; i++)
        maxField = findMaxSubField(D, n, stack, maxField, i);

    free(D);
    free(stack);

    return maxField;
}

int main()
{
    int n, i, j, sum=0, maxField;
    scanf("%d", &n);

    int **A = mallocArray2D(n, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
            sum += A[i][j];
        }
    }

    if (sum == 0 || sum == n*n)
        maxField = n*n - sum;
    else
        maxField = findMaxField(A, n);

    printf("%d", maxField);

    free(A);

    return 0;
}
