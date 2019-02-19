#include <stdio.h>

#define len(array) (sizeof(array)/sizeof(array[0])) // get array lenght

// sort functions
void bubble(int *array, int n);
void selection(int *array, int n);
void insertion(int *array, int n);
void mergesort(int *arr, int l, int r);
void merge(int *arr, int l, int m, int r); // merge subarrays

// helper functions
void exchange(int *a, int *b);  // exchange values between two variables

int main(void){
    int a[5] = {2,5,6,7,1};
    int _len = len(a);

    printf("original array:\n");
    for(int i=0; i<5; i++) printf("%d", a[i]);

    printf("\n------------------------\n");
    mergesort(a, 0, _len);

    printf("sorted array:\n");
    for(int i=0; i<5; i++) printf("%d", a[i]);
    printf("\n");

    return 0;
}

void exchange(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble(int *array, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(array[j] > array[j+1]){
                exchange(&array[j], &array[j+1]);
            }
        }
    }
}

void selection(int *array, int n){
    for(int i=0; i<n; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(array[min] > array[j]){
                min = j;
            }
        }

        exchange(&array[min], &array[i]);
    }
}

void insertion(int *array, int n){
    for (int i=1; i<n; i++){
        int tmp = array[i];
        int j = i - 1;

        while (array[j]>tmp && j>=0){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = tmp;
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void mergesort(int *arr, int l, int r){
    if (l < r){
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int *arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int LEFT[n1], RIGHT[n2];  // create temp arrays

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        LEFT[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        RIGHT[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2){
        if (LEFT[i] <= RIGHT[j]){
            arr[k] = LEFT[i];
            i++;
        }else{
            arr[k] = RIGHT[j];
            j++;
        }

        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1){
        arr[k] = LEFT[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2){
        arr[k] = RIGHT[j];
        j++;
        k++;
    }
}