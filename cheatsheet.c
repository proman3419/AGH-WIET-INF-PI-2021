// calloc array 1D =======================================================
int* callocArray(int n)
{
    int *A = (int *)calloc((unsigned int)n, sizeof(int));

    return A;
}
//========================================================================

// malloc array 1D =======================================================
int* mallocArray(int n)
{
    int *A = (int *)malloc((unsigned int)n*sizeof(int));

    return A;
}
//========================================================================

// calloc array 2D =======================================================
int** callocArray2D(int r, int c)
{
    int **A = (int **)malloc((unsigned int)r*sizeof(int *));
    for (int i = 0; i < r; i++)
        A[i] = (int *)calloc((unsigned int)c, sizeof(int));

    return A;
}
//========================================================================

// malloc array 2D =======================================================
int** mallocArray2D(int r, int c)
{
    int **A = (int **)malloc((unsigned int)r*sizeof(int *));
    for (int i = 0; i < r; i++)
        A[i] = (int *)malloc((unsigned int)c*sizeof(int));

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

// read into array 2D ====================================================
void readIntoArray2D(int **A, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &A[i][j]);
}
//========================================================================

// print array 1D ========================================================
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
//========================================================================

// print array 2D ========================================================
void printArray2D(int **A, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//========================================================================

// swap ==================================================================
void swap(int *A, int i, int j)
{
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}
//========================================================================

// quick sort ============================================================
int partition(int *A, int l, int r)
{
    int i = l - 1;
    for (int j = l; j < r; j++)
        if (A[j] < A[r])
            swap(A, ++i, j);

    swap(A, ++i, r);

    return i;
}

void quickSort(int *A, int l, int r)
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
