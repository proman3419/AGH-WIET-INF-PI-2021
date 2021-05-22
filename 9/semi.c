#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>

int32_t power(int x, int n)                                                   
{                                                                              
    int32_t res = 1;                                                         
    for (int i = 0; i < n; i++)                                               
        res *= x;                                                                                                                                     
    return res;                                                                
} 

int32_t cntSemiMultiples(int N, int M)
{
    if (M == 1)
        return 0;

    int32_t maxVal=power(2, N), cnt=0, curr;

    for (int32_t i = 1; i < maxVal; i++)
    {
        for (int j = 0; j < N; j++)
        {
            curr = i^(1 << j);
            if (i%M != 0 && curr != 0 && curr%M == 0)
            {
                cnt++;
                break;
            }
        }
    }

    return cnt;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int32_t cnt = cntSemiMultiples(N, M);
    printf("%"PRId32, cnt);

    return 0;
}
