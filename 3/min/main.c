#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int A[], int i, int j)
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int partition(int A[], int l, int r)
{
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (A[j] < A[r])
        {
            i++;
            swap(A, i, j);
        }
    }

    i++;
    swap(A, i, r);

    return i;
}

void quickSort(int A[], int l, int r)
{
    int pi;
    while (l < r)
    {
        pi = partition(A, l, r);
        if (pi - l < r - pi)
        {
            quickSort(A, l, pi-1);
            l = pi + 1;
        }
        else
        {
            quickSort(A, pi+1, r);
            r = pi - 1;
        }
    }
}

void fixOrder(int A[], int N)
{
    int i = N - 2, cmp = A[N-1];
    while (i >= 0 && A[i] > cmp)
    {
        swap(A, i, i+1);
        i--;
    }
    A[++i] = cmp;
}

int findMinSum(int A[], int N, int K, int sum)
{
    if (N == 1)
    {
        while (K > 0 && A[0] > 0)
        {
            sum -= (int)ceil(A[0]/2.0);
            A[0] /= 2;
            K--;
        }
    }
    else
    {
        int i = N - 1;
        while (K > 0 && A[i] > 0)
        {
            while (K > 0 && A[i] >= A[i-1])
            {
                sum -= (int)ceil(A[i]/2.0);
                A[i] /= 2;
                K--;
            }
            fixOrder(A, N);
        }
    }

    return sum;
}

int main()
{
    int N, K, sum=0;
    scanf("%d %d", &N, &K);

    int A[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
        sum += A[i];
    }

    quickSort(A, 0, N-1);
    printf("%d", findMinSum(A, N, K, sum));

    return 0;
}
