#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int getNumberLen(int64_t S)
{
    int len = 0;
    while (S > 0)
    {
        len++;
        S /= 10;
    }

    return len;
}

int64_t findX(int64_t S)
{
    int lenS = getNumberLen(S);
    int64_t k = 0;
    for (int i = 0; i < lenS; i++)
        k = 10*k + 1;
    int64_t X = 0;

    while (S > 0)
    {
        X = 10*X + S/k;
        S = S - (S/k)*k;
        k /= 10;
    }

    return X;
}

int64_t calculateS(int64_t X)
{
    int64_t S = 0;
    while (X > 0)
    {
        S += X;
        X /= 10;
    }

    return S;
}

int main()
{
    int64_t S;
    scanf("%"PRId64, &S);

    int64_t X = findX(S);
    int64_t XS = calculateS(X);

    if (XS == S)
        printf("%"PRId64, X);
    else
        printf("-1");

    return 0;
}
