#include <stdio.h>
#include <stdlib.h>

int isOneSquared(int n)
{
    int squaredSum;
    for (;;)
    {
        squaredSum = 0;
        while (n > 0)
        {
            squaredSum += (n%10)*(n%10);
            n /= 10;
        }

        n = squaredSum;
        if (n == 4) return 0;
        if (n == 1) return 1;
    }
}

int isPrime(int x)
{
    if (x < 2) return 0;
    if (x == 2 || x == 3) return 1;
    if (x%2 == 0 || x%3 == 0) return 0;

    int i = 3;
    while (i*i <= x)
    {
        if (x%i == 0)
            return 0;
        i += 2;
    }

    return 1;
}

int main()
{
    int L, U, K;
    scanf("%d %d %d", &L, &U, &K);

    for (int i = L; i <= U; i++)
    {
        if (isPrime(i) && isOneSquared(i))
        {
            K--;
            if (K == 0)
                printf("%d", i);
        }
    }

    if (K > 0)
        printf("-1");

    return 0;
}
