#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a=0, b=1, c;
    scanf("%d", &n);

    while (a*b < n)
    {
        c = a;
        a = b;
        b += c;
    }

    if (a*b == n)
        printf("YES");
    else
        printf("NO");

    return 0;
}
