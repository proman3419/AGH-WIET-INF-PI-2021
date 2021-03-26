#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 1000

int findHalfIndex(int A[], int n, long sum)
{
    if (n == 1)
        return 0;

    long sumL=0, sumR=sum-A[0];
    int hi = 1;
    while (hi < n && sumL != sumR)
    {
        sumL += A[hi-1];
        sumR -= A[hi];
        hi++;
    }

    return hi - 1;
}

int main()
{
    int A[ARR_SIZE];
    int n;
    scanf("%d", &n);

    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        sum += A[i];
    }

    int halfIndex = findHalfIndex(A, n, sum);
    printf("%d", halfIndex);

    return 0;
}
