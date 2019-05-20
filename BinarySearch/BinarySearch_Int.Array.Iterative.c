/*********************************************************************
* Filename:  BinarySearch_Int.Array.Iterative.c
* Author:    Javier Montenegro (www.javiermontenegro.com)
* Copyright:
* Details:   This code is the implementation of the binary search algorithm.
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NARRAY 8  /* array size */

int binarySearchIterative(int array[], int n, int number);
void print(int arr[]);
//Iterative Binary Search Algorithm
int binarySearchIterative(int array[], int n, int number) {
    int mid;
    int low =  0;
    int high = n-1;
    while (low <= high) {
        mid  = low + (high-low)/2; //To avoid overflow
        if(array[mid] == number)
            return mid;
        else if(array[mid] < number)
            low =  mid + 1;
        else high =  mid - 1;
    }//End while

    return -1;
}//End binarySearchIterative

void print(int arr[])
{
    int i;
    for(i = 0; i < NARRAY; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}//End print

int main()
{
    int array[NARRAY] = {3,6,19,25,33,39,55,78}; 
    int number = 39;
    
    printf("Initial array\n");
    print(array);
    printf("------------\n");
    
    clock_t start = clock();
    printf("\nElement %d is at location: %d", number, binarySearchIterative(array, NARRAY, number));
    
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n\nTime spent searching: %f\n", time_spent);
    return 0;
}//End main