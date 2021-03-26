#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

int sumFactors(int x)
{
    if (x == 1)
        return 0;

    int sum=1, i=2;
    while (i*i < x)
    {
        if (x%i == 0)
            sum += i + x/i;
        i++;
    }

    if (i*i == x)
        sum += i;

    return sum;
}


int main()
{
    int m, n, i=0, cnt=0;
    scanf("%d %d", &m, &n);
    int perfectNums[ARRAY_SIZE];

    for (;m <= n; m++)
    {
        if (sumFactors(m) == m)
        {
            perfectNums[i] = m;
            i++;
            cnt++;
        }
    }

    printf("%d\n", cnt);

    for (int j = 0; j < i; j++)
        printf("%d ", perfectNums[j]);

    return 0;
}
