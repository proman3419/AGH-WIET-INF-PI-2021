#include <stdio.h>
#include <stdlib.h>

int getStringLen(char *s)
{
    int len = 0;
    while (s[len] != '\0')
        len++;

    return len;
}

void findLargestSubstring(char *s)
{
    int i, curr, last=-1, n;
    n = getStringLen(s);

    while (last < n-1)
    {
        curr = last+1;
        for (i = curr+1; i < n; i++)
        {
            if (s[i] > s[curr])
                curr = i;
        }
        printf("%c", s[curr]);
        last = curr;
    }
}

int main()
{
    char s[50];
    scanf("%s", s);

    findLargestSubstring(s);

    return 0;
}
