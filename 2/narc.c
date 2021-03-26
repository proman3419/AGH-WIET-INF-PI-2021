#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isNarcistic(int n, int b, int m)
{
    int tmp = n;
    while (tmp > 0)
    {
        n -= ceil(pow((double)(tmp%b), m));
        tmp /= b;
    }

    if (n == 0)
        return 1;
    return 0;
}

void printInBase(int n, int b, int m)
{
    int curr, i;
    char res[m];

    for (i = 0; i < m; i++)
    {
        curr = n%b;
        if (curr < 10)
            res[i] = curr + '0';
        else
            res[i] = curr%10 + 'A';
        n /= b;
    }

    for (i = m-1; i >= 0; i--)
        printf("%c", res[i]);
    printf(" ");
}

int main()
{
    int m, b;
    scanf("%d %d", &m, &b);

    int minVal = ceil(pow((double)b, m-1));
    int maxVal = ceil(pow((double)b, m)) - 1;
    int flag = 0;

    for (int i = minVal; i <= maxVal; i++)
    {
        if (isNarcistic(i, b, m))
        {
            printInBase(i, b, m);
            flag = 1;
        }
    }

    if (flag == 0)
        printf("NO");

    return 0;
}
