#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int64_t f(int x)
{
    if (x == 0)
        return 0;

    int64_t k = (x+1)/2;

    return k*k + f(x/2);
}

int main()
{
    int N;
    scanf("%d", &N);

    int64_t sum = f(N);
    printf("%"PRId64, sum);

    return 0;
}
