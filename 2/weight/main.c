#include <stdio.h>
#include <stdlib.h>

int weigh(int weights[], int *n, int w, int i)
{
    if (w == 0)
        return 1;

    if (i == *n)
        return 0;

    return weigh(weights, n, w-weights[i], i+1) + weigh(weights, n, w+weights[i], i+1);
}

int main()
{
    int n, w;
    scanf("%d %d", &n, &w);

    int weights[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &weights[i]);

    int res = weigh(weights, &n, w, 0);
    if (res > 0)
        printf("YES");
    else
        printf("NO");

    return 0;
}
