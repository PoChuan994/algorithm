/* Refered from https://www.geeksforgeeks.org/merge-sort/ */

#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temparory arrays */
    int L[n1], R[n2];

    /* Copy data to temparory array */
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        /* the starting position of second array is m + 1 */
        R[i] = arr[m + 1 + i];

    /* 
     * l is the index of left (first) array
     * r is the index of right (second) arry
     * k is the index of merged array
     */
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* copy the remaining element into arr */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is the leftmost index and r is the rightmost index */
void merge_sort(int arr[], int l, int r)
{
    if (l < r)  {
        int m = (l + r - 1) / 2;

        /* Divide arr into two sub-array and sort both array */
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main ()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    display(arr, arr_size);
    
    merge_sort(arr, 0, arr_size - 1);
    printf("\nSorted Array is \n");
    display(arr, arr_size);
    return 0;
}
