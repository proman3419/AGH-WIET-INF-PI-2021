// print array ===========================================================
void printArray(int A[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}
//========================================================================

// swap ==================================================================
void swap(int A[], int i, int j)
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}
//========================================================================

// quick sort ============================================================
int partition(int A[], int l, int r)
{
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (A[j] < A[r])
        {
            i++;
            swap(A, i, j);
        }
    }

    i++;
    swap(A, i, r);

    return i;
}

void quickSort(int A[], int l, int r)
{
    int pi;
    while (l < r)
    {
        pi = partition(A, l, r);
        if (pi - l < r - pi)
        {
            quickSort(A, l, pi-1);
            l = pi + 1;
        }
        else
        {
            quickSort(A, pi+1, r);
            r = pi - 1;
        }
    }
}
//========================================================================

// is prime ==============================================================
int isPrime(int x)
{
    if (x < 2) return 0;
    if (x == 2 || x == 3) return 1;
    if (x%2 == 0 || x%3 == 0) return 0;

    int i = 3;
    while (i*i <= x)
    {
        if (x%i == 0)
            return 0;
        i += 2;
    }

    return 1;
}
//========================================================================
