/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

bool invalidate(int argc);

int main(int argc, string argv[])
{
    // TODO: comment me
    if (invalidate(argc)) return 1;

    // TODO: comment me
    int n = atoi(argv[1]);

    // TODO: comment me
    srand48((long int) (argc == 3) ? atoi(argv[2]) : time(NULL));

    // TODO: comment me
    for (int i = 0; i < n; i++){
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}

bool invalidate(int argc){
    if (argc != 2 && argc != 3){
        printf("Usage: generate n [s]\n");
        return true;
    }
    return false;
}