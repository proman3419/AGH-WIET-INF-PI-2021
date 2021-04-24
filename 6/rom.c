#include <stdio.h>
#include <stdlib.h>

#define MAX_ROMAN_LEN 25
#define VALUES_LEN 13

// calloc array 1D =======================================================
char* callocArrayChar(char n)
{
    char *A = (char *)calloc((unsigned char)n, sizeof(char));

    return A;
}
//========================================================================

int romanToIntDict(char ch)
{
    switch (ch)
    {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

void intToRomanDict(int val, char *res)
{
    switch (val)
    {
    case 1: res[0] = 'I'; res[1] = ' '; break;
    case 4: res[0] = 'I'; res[1] = 'V'; break;
    case 5: res[0] = 'V'; res[1] = ' '; break;
    case 9: res[0] = 'I'; res[1] = 'X'; break;
    case 10: res[0] = 'X'; res[1] = ' '; break;
    case 40: res[0] = 'X'; res[1] = 'L'; break;
    case 50: res[0] = 'L'; res[1] = ' '; break;
    case 90: res[0] = 'X'; res[1] = 'C'; break;
    case 100: res[0] = 'C'; res[1] = ' '; break;
    case 400: res[0] = 'C'; res[1] = 'D'; break;
    case 500: res[0] = 'D'; res[1] = ' '; break;
    case 900: res[0] = 'C'; res[1] = 'M'; break;
    case 1000: res[0] = 'M'; res[1] = ' '; break;
    default: res[0] = ' '; res[1] = ' '; break;
    }
}

int romanToInt(char *roman)
{
    int res=0, i=0, toAdd;
    while (i < MAX_ROMAN_LEN-1 && romanToIntDict(roman[i]) != 0)
    {
        toAdd = romanToIntDict(roman[i]);
        if (romanToIntDict(roman[i+1]) <= toAdd)
            res += toAdd;
        else
            res -= toAdd;

        i++;
    }

    return res;
}

void intToRomanPrint(int *values, int val)
{
    if (val <= 0)
        return;

    char temp[] = {' ', ' '};
    int i;
    for (i = VALUES_LEN-1; i >= 0; i--)
    {
        while (val >= values[i])
        {
            intToRomanDict(values[i], temp);
            printf("%c", temp[0]);
            if (temp[1] != ' ')
                printf("%c", temp[1]);
            val -= values[i];
        }
    }

    printf("\n");
}

int main()
{
    int values[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    char *roman = callocArrayChar(MAX_ROMAN_LEN);
    int res=0;

    scanf("%s", roman);
    res = romanToInt(roman);
    free(roman);

    roman = callocArrayChar(MAX_ROMAN_LEN);
    scanf("%s", roman);
    res += romanToInt(roman);
    free(roman);

    intToRomanPrint(values, res);

    return 0;
}
