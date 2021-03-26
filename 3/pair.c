#include <stdio.h>
#include <stdlib.h>

int findPairs(int A[], unsigned int N, int K)
{
    // one element
    if (N == 1)
        return 0;

    int cnt=0, i=0, j=0;

    while (j < N-1 && A[j+1] == A[j])
        j++;

    // one unique value
    if (j == N-1)
        return 0;

    // consider start
    if (A[j+1] <= A[j]+K)
        cnt += j + 1;
    i = j + 1;

    while (i < N)
    {
        j = i;
        for (;;)
        {
            // consider end
            if (j == N-1)
            {
                if (A[i-1] >= A[i]-K)
                    cnt += j - i + 1;
                return cnt;
            }
            if (A[j+1] != A[j])
                break;
            j++;
        }

        if (A[i-1] >= A[i]-K)
            cnt += j - i + 1;
        else if (A[j+1] <= A[j]+K)
            cnt += j - i + 1;

        i = j + 1;
    }

    return cnt;
}

int cmpFunc (const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    unsigned int N;
    int K;
    scanf("%d %d", &N, &K);

    int *A = (int*)calloc(N, sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    qsort(A, N, sizeof(int), cmpFunc);
    printf("%d", findPairs(A, N, K));

    free(A);

    return 0;
}
