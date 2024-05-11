#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// we define the macro ARRAY_SIZE to be 1000
#define ARRAY_SIZE 1000

// we define the main function of the array sum

int main()
{
    int i;
    int sum = 0;
    int array[ARRAY_SIZE]; // we declare an array of size 1000 of integers
    float start_time, end_time;


   

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


 // ========= PARALLEL SUM ============

    // we start the timer
    start_time = omp_get_wtime();
    // here we will be using openmm to calculate the sum of the array in a parallel way
    #pragma omp parallel for reduction(+ : sum) // this is a reduction clause
    // it instructs the compiler to parallelize the loop over the array, using threads 
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        sum += array[i];
    }
    // we end the timer
    end_time = omp_get_wtime();

    printf("The sum of the array is: %d\n", sum);
    printf("[ PARALLEL ] The time taken is: %f\n", end_time - start_time);


// ========= SEQUENTIAL SUM ============
    sum = 0;
    start_time = omp_get_wtime();
    for (i = 0; i < ARRAY_SIZE; i++){
        sum += array[i];
    }
    end_time = omp_get_wtime();
    printf("The sum of the array is: %d\n", sum);
    printf("[ SEQUENTIAL ] The time taken is: %f\n", end_time - start_time);

    return 0;
}
