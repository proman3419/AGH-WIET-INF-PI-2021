#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LEN 50
#define PRIMES_CNT 15

// malloc array 1D =======================================================
char* mallocArrayChar(int n)
{
    char *A = (char *)malloc((unsigned char)n*sizeof(char));

    return A;
}
//========================================================================

// get string len ========================================================
int getStringLen(char *s)
{
    int len = 0;
    while (s[len] != '\0')
        len++;

    return len;
}
//========================================================================

void copyString(char *from, char *to, int n)
{
    for (int i = 0; i < n; i++)
        to[i] = from[i];
}

// {-1: s1 > s2, 0: s1 == s2, 1: s1 < s2}
int compareLexicographicallyStrings(char *s1, char *s2, int n)
{
    int i = 0;
    while (s1[i] == s2[i])
        i++;

    if (i == n)
        return 0;

    if (s1[i] > s2[i])
        return -1;
    return 1;
}

void generateString(char *s, char *sGen, int n, int o, int p)
{
    for (int i = 0; i < n; i++)
        sGen[i] = s[(o+i*p)%n];
}

char* findSmallestLexicographicallyString(char *s, int n)
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    char *sGen = mallocArrayChar(n+1); // +1 dla '\0'
    char *sMin = mallocArrayChar(n+1); // +1 dla '\0'
    char *temp;

    copyString(s, sMin, n);

    for (int o = 0; o < n; o++)
    {
        for (int p = 0; p < PRIMES_CNT; p++)
        {
            if (primes[p] >= n)
                break;

            generateString(s, sGen, n, o, primes[p]);
            
            if (compareLexicographicallyStrings(sMin, sGen, n) == -1)
            {
                temp = sMin;
                sMin = sGen;
                sGen = temp;
            }
        }
    }

    free(sGen);

    return sMin;
}

int main()
{
    char *s = mallocArrayChar(MAX_STRING_LEN+1); // +1 dla '\0'
    scanf("%s", s);

    int n = getStringLen(s);
    char *sol = findSmallestLexicographicallyString(s, n);
    printf("%s", sol);

    free(s);
    free(sol);

    return 0;
}
