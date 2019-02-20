/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

void exchange(int *a, int *b);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n){
    for(int i=0; i<n; i++){
        if(value == values[i]){
            return true;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int array[], int n){
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

void exchange(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}