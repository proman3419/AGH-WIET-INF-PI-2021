#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int containsConsecutiveOnes(int n)
{
    int prev = 0;
    while (n > 0)
    {
        if (n%2 == 1)
            if (prev == 1)
                return 1;

        prev = n%2;
        n /= 2;
    }

    return 0;
}

int reverseNum(int n)
{
    int res = 0;
    while (n > 0)
    {
        res = 2*res + n%2;
        n /= 2;
    }

    return res;
}

void printBin(int N, int n)
{
    int lenn = (n == 0) ? 1 : ((int)log2(n))+1;
    int i;

    for (i = lenn; i < N; i++)
        printf("0");

    n = reverseNum(n);

    for (i = 0; i < lenn; i++)
    {
        printf("%d", n%2);
        n /= 2;
    }
}

void findSequence(int N, int K)
{
    int max = (int)pow(2, N);
    int i = 0;

    while (i < max && K > 0)
    {
        if (containsConsecutiveOnes(i) == 0)
            K--;
        i++;
    }

    if (K == 0)
        printBin(N, --i);
    else
        printf("-1");
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    findSequence(N, K);

    return 0;
}
