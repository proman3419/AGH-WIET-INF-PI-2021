#include <stdio.h>
#include <stdlib.h>

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

int digitsIncSeq(int x)
{
    int last = 9;
    while (x > 0)
    {
        if (x%10 > last)
            return 0;
        last = x%10;
        x /= 10;
    }

    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 2; i < n; i++)
        if (isPrime(i) && digitsIncSeq(i))
            printf("%d\n", i);

    return 0;
}
