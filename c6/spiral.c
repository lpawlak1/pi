#include <stdio.h>
#include <malloc.h>


int main(void)
{
    int n;
    scanf("%d",&n);
    int *a = (int *)malloc(n * n * sizeof(int));
    int i, j;

    i = n-1;
    j = 0;
    int l = 1;
    while(i != 0){
        int k = 0;
        // poziom gora
        for (k = j; k < i; k++) a[(j*n)+k] = l++;
        // pion prawo
        for (k = j; k < i; k++) a[(k*n)+i] = l++;
        // poziom dol
        for (k = i; k > j; k--) a[(i*n)+k] = l++;
        // pion lewo
        for (k = i; k > j; k--) a[(k*n)+j] = l++;
        i--;
        j++;
    }
    if (n % 2 == 1)
        a[((n/2)*n)+(n/2)] = l;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", a[(i*n)+j]);
        printf("\n");
    }
    free(a);
    return 0;
}
