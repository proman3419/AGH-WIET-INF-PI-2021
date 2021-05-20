#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// malloc array 1D =======================================================
int* mallocArray(int n)
{
    int *A = (int *)malloc((unsigned int)n*sizeof(int));

    return A;
}
//========================================================================

// read into array =======================================================
void readIntoArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
}
//========================================================================

// calloc array 1D =======================================================
int* callocArray(int n)
{
    int *A = (int *)calloc((unsigned int)n, sizeof(int));

    return A;
}
//========================================================================

// qsort =================================================================
int cmpFunc (const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}
//========================================================================

// jezeli G wystepuje w T to i tak musimy je usunac.
// zastepujemy to wystapienie zerem, zeby nie liczyc drugi raz w possiblePowsCnts
int checkIfContainsG(int N, int G, int *T)
{
    for (int i = 0; i < N; i++)
    {
        if (T[i] == G)
        {
            T[i] = 0;
            return 1;
        }
    }

    return 0;
}

int findStartingIndex(int N, int G, int *T)
{
    int i = 0;
    while (i < N && T[i] > G)
        i++;

    return i;
}

int* generatePossiblePowsCnts(int maxPowExp, int N, int G, int *T)
{
    int *possiblePowsCnts = callocArray(maxPowExp+1);
    int *currPossiblePowsCnts = callocArray(maxPowExp+1);
    int i = findStartingIndex(N, G, T);
    int j, curr, currG, flag;

    for (; i < N; i++)
    {
        curr = T[i];
        currG = G;
        flag = 1;
        for (j = 0; j <= maxPowExp; j++)
        {
            if (currG%2 == 0 && curr%2 == 1)
            {
                flag = 0;
                break;
            }
            currPossiblePowsCnts[j] += curr%2;
            curr /= 2;
            currG /= 2;
        }

        for (j = 0; j <= maxPowExp; j++)
        {
            if (flag == 1)
                possiblePowsCnts[j] += currPossiblePowsCnts[j];
            currPossiblePowsCnts[j] = 0;
        }
    }

    free(currPossiblePowsCnts);

    return possiblePowsCnts;
}

int findSolution(int maxPowExp, int *possiblePowsCnts, int G)
{
    int min = INT_MAX;

    for (int i = 0; i <= maxPowExp; i++)
    {
        if (G%2 == 1 && possiblePowsCnts[i] < min)
            min = possiblePowsCnts[i];

        G /= 2;
    }

    return min;
}

int findMinElementsCntToRemove(int N, int G, int *T)
{
    int solution = checkIfContainsG(N, G ,T);

    qsort(T, (unsigned int)N, sizeof(int), cmpFunc);

    int maxPowExp = (int)ceil(log2(G));
    int *possiblePowersCnts = generatePossiblePowsCnts(maxPowExp, N, G, T);

    solution += findSolution(maxPowExp, possiblePowersCnts, G);

    free(possiblePowersCnts);

    return solution;
}

int main()
{
    int N, G;
    scanf("%d %d", &N, &G);

    int *T = mallocArray(N);
    readIntoArray(T, N);

    int res = findMinElementsCntToRemove(N, G, T);
    printf("%d", res);

    free(T);

    return 0;
}
