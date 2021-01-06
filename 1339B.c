#include <stdio.h>
#include <stdlib.h>

void merge(long int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    long int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(long int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int t, n, pivot, d;
    long int *A;

    scanf("%d", &t);

    for (int i = 0; i < t; ++i)
    {
        scanf("%d", &n);
        A = (long int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j)
            scanf("%ld", A + j);
        mergeSort(A, 0, n - 1);

        pivot = n / 2 - (n % 2 == 0 ? 1 : 0);
        d = 1;
        printf("%ld ", A[pivot]);
        while (d <= n / 2)
        {
            printf("%ld ", A[pivot + d]);
            if (pivot - d > -1)
                printf("%ld ", A[pivot - d]);
            d++;
        }
        printf("\n");

        free(A);
        A = NULL;
    }
}