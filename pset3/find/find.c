/**
 * find.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Prompts user for as many as MAX values until EOF is reached,
 * then proceeds to search that "haystack" of values for given needle.
 *
 * Usage: ./find needle
 *
 * where needle is the value to find in a haystack of values
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

bool invalidate(int argc);
int * values();

// maximum amount of hay
const int MAX = 65536;
int size = -1;

int main(int argc, string argv[])
{
    // ensure proper usage
    if (invalidate(argc)) return 1;

    // remember needle
    int needle = atoi(argv[1]);

    // fill haystack
    int *haystack;
    haystack = values();

    // sort the haystack
    sort(haystack, size);

    // try to find needle in haystack
    bool findResult = search(needle, haystack, size);
    string msg = (findResult) ? "\nFound needle in haystack!\n\n" : "\nDidn't find needle in haystack.\n\n";

    printf("%s", msg);
    return (findResult) ? 0 : 1;
}

bool invalidate(int argc){
    if (argc != 2){
        printf("Usage: ./find needle\n");
        return true;
    }
    return false;
}

int * values(){
    static int haystack[MAX];
    for (size = 0; size < MAX; size++){
        // wait for hay until EOF
        //printf("\nhaystack[%i] = ", size);
        int straw = get_int("");
        if (straw == INT_MAX) break;

        // add hay to stack
        haystack[size] = straw;
    }

    return haystack;
}