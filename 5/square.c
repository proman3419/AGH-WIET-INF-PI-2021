#include <stdio.h>
#include <stdlib.h>

void findSquares(int **T, int n, int k)
{
    int i, j, l, m, sum, q=0;

    int *squaresIds = (int *)calloc((unsigned int)(n*n-4*n+4), sizeof(int));

    for (i = 1; i < n-1; i++)
    {
        for (j = 1; j < n-1; j++)
        {
            l = 3; // dlugosc boku
            sum = 0;

            while (i-l/2 >= 0 && i+l/2 < n && j-l/2 >= 0 && j+l/2 < n)
            {
                for (m = 0; m < l-1; m++)
                {
                    /*
                          1 -> .
                        4#######
                         #     #2
                        |#     #
                        v#  @  #|
                         #     #v
                        .#     #
                         #######.
                         3 -> .

                        1. [i-l/2][j-l/2+1+m] -> [i-l/2][j+l/2]
                        2. [i-l/2+1+m][j+l/2] -> [i+l/2][j+l]
                        3. [i+l/2][j-l/2+m]   -> [i+l/2][j+l/2-1]
                        4. [i-l/2+m][j-l/2]   -> [i+l/2-1][j+l/2-1]
                    */
                    sum += T[i-l/2][j-l/2+1+m] + T[i-l/2+1+m][j+l/2] + T[i+l/2][j-l/2+m] + T[i-l/2+m][j-l/2];
                }

                if (sum == k)
                    squaresIds[q++] = i*n + j;

                l += 2;
            }
        }
    }

    printf("%d\n", q);

    for (i = 0; i < q; i++)
        printf("%d %d\n", squaresIds[i]/n, squaresIds[i]%n);

    free(squaresIds);
}

int main()
{
    int n, k, i, j;
    scanf("%d %d", &n, &k);

    int **T = (int **)malloc((unsigned int)n*sizeof(int *));
    for (i = 0; i < n; i++)
        T[i] = (int *)malloc((unsigned int)n*sizeof(int));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &T[i][j]);

    findSquares(T, n, k);

    free(T);

    return 0;
}
