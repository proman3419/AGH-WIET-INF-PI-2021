#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN 160
#define MAX_DIGITS 3

void fillArr(int *A, int n, int val)
{
    for (int i = 0; i < n; i++)
        A[i] = val;
}

void intToArr(int val, int *A, int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        A[i] = val%10;
        val /= 10;

        if (val == 0)
            return;
    }
}

void printArrAsInt(int *A, int n)
{
    int i = 0;
    while (i < n && A[i] == 0)
        i++;

    if (i == n)
    {
        printf("0\n");
        return;
    }

    for (; i < n; i++)
        printf("%d", A[i]);
    printf("\n");
}

void shiftArr(int *A, int n, int k)
{
    int i;
    for (i = k; i < n; i++)
        A[i-k] = A[i];
    for (i = 1; i <= k; i++)
        A[n-i] = 0;
}

void multiplyByDigit(int *A, int digit, int *res, int n)
{
    int tmp, carry=0;
    for (int i = n-1; i >= 0; i--)
    {
        tmp = A[i]*digit + carry;
        res[i] = tmp%10;
        carry = tmp/10;
    }
}

// res goes into A
void add(int *A, int *B, int n)
{
    int tmp, carry=0;

    for (int i = n-1; i >= 0; i--)
    {
        tmp = A[i] + B[i] + carry;
        A[i] = tmp%10;
        carry = tmp/10;
    }
}

int* multiply(int *A, int val, int *res, int **tmps, int n)
{
    int i = 0;
    while (val != 0)
    {
        multiplyByDigit(A, val%10, tmps[i], n);
        if (i > 0)
            shiftArr(tmps[i], n, i);
        val /= 10;
        i++;
    }

    for (i = 0; i < MAX_DIGITS; i++)
        add(res, tmps[i], n);

    return res;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *A = (int *)calloc(ARR_LEN, sizeof(int));
    int *res = (int *)calloc(ARR_LEN, sizeof(int));

    int **tmps = (int **)malloc(MAX_DIGITS*sizeof(int *));
    for (int i = 0; i < MAX_DIGITS; i++)
        tmps[i] = (int *)calloc(ARR_LEN, ARR_LEN*sizeof(int));

    intToArr(1, A, ARR_LEN);

    int *tmp;
    for (int i = 2; i <= n; i++)
    {
        tmp = A;
        A = multiply(A, i, res, tmps, ARR_LEN);
        res = tmp;
        fillArr(res, ARR_LEN, 0);
    }

    printArrAsInt(A, ARR_LEN);

    free(A);
    free(res);
    free(tmps);

    return 0;
}
