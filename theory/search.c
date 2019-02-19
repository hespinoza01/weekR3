#include <stdio.h>
#include <cs50.h>

#define len(array) (sizeof(array)/sizeof(array[0])) // get array lenght

// search functions
bool linearsearch(int array[], int n, int value);
bool binarysearch(int array[], int n, int value);

int main(void){
    int a[] = {1,2,3,4,5,6};
    int _len = len(a);

    binarysearch(a, _len, 4) ? printf("found\n") : printf("not found\n");

    return 0;
}

bool linearsearch(int array[], int n, int value){
    for(int i=0; i<n; i++){
        if(value == array[i])
            return true;
    }
    return false;
}

bool binarysearch(int array[], int n, int value){
    int min=0, md, max=n-1;

    while(min <= max){
        int index = (min + max) / 2;
        md = array[index];

        if(value == md)
            return true;
        else if(value < md)
            max = index - 1;
        else
            min = index + 1;
    }

    return false;
}