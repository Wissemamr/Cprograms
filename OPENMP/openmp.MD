# Introduction to parallel computing : 
The goal is to get more familiar with parallel computing, I will be suing OpemMP
In this small project, we will try to fully grasp how parallelization happens, we will do this byy a simple example which consists of calculating the sum of elements in an array

``` C
 #pragma omp parallel for reduction(+ : sum)
```


`reduction(+:sum)`: This is a clause of the OpenMP pragma that specifies how to handle the reduction of variables across multiple threads. Here's what it does:

- `reduction`: Indicates that the operation specified within the parentheses will be performed in a reduction manner, meaning that each thread will have its own local copy of the variable sum, and at the end of the parallel region, these local copies will be combined (reduced) to produce a single result.
- `+`: Specifies the reduction operation to be performed, in this case, addition.
- `sum`: Indicates the variable to be reduced across threads. In this case, sum is the variable storing the sum of elements in the array.