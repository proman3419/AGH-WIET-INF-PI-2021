#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int *A, int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int findMinId(int **t1, int *ids, int N)
{
    int minVal=INT_MAX, minId=-1;

    for (int i = 0; i < N; i++)
    {
        if (ids[i] < N && t1[i][ids[i]] <= minVal)
        {
            minVal = t1[i][ids[i]];
            minId = i;
        }
    }

    return minId;
}

void skipDuplicates(int **t1, int *ids, int N, int val)
{
    for (int i = 0; i < N; i++)
        while (ids[i] < N && t1[i][ids[i]] == val)
            ids[i]++;
}

int merge(int **t1, int *t2, int N)
{
    int *ids = (int *)calloc((unsigned int)N, sizeof(int));

    int minId, i=0;
    for (;;)
    {
        minId = findMinId(t1, ids, N);
        if (minId == -1)
            break;

        t2[i] = t1[minId][ids[minId]];
        skipDuplicates(t1, ids, N, t2[i]);
        i++;
    }

    free(ids);

    return i;
}

int main()
{
    int N, i, j;
    scanf("%d", &N);

    int **t1 = (int **)malloc((unsigned int)N*sizeof(int *));
    for (i = 0; i < N; i++)
        t1[i] = (int *)malloc((unsigned int)N*sizeof(int));

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &t1[i][j]);

    int *t2 = (int *)malloc((unsigned int)(N*N)*sizeof(int));

    int mergedN = merge(t1, t2, N);

    printArray(t2, mergedN);

    free(t1);
    free(t2);

    return 0;
}
