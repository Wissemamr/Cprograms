#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <stdbool.h>

// we define the macro ARRAY_SIZE to be 1000
#define ARRAY_SIZE 1000

// we define the main function of the array sum

int main()
{
    int i;
    int sum = 0;
    int array[ARRAY_SIZE]; // we decalre an array of size 1000 of integers

    // here we initialise the array with numbers from 1 to 1000
    //  array = [1,2,3,4,5,6,..., 1000]
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = i + 1;
    }

    bool SHOW_ARRAY = false;
    if (SHOW_ARRAY)
    {
        printf("The array is:\n");
        for (i = 0; i < ARRAY_SIZE; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    // here we will be using openmm to calculate the sum of the array in a parallel way
    // this is a reduction clause to ensure each thread has its own local copy of the sum
    #pragma omp parallel for reduction(+ : sum) // this is a reduction clause
    // it instructs the compiler to parallelize the loop over the array, using threads 
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        sum += array[i];
    }
    printf("The sum of the array is: %d\n", sum);
    return 0;
}
