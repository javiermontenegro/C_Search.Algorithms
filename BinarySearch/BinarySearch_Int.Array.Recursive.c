#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NARRAY 8  /* array size */

int binarySearchRecursive(int array[], int low, int high, int number);
void print(int arr[]);
//Recursive Binary Search Algorithm
int binarySearchRecursive(int array[], int low, int high, int number) {
    int mid  = low + (high-low)/2; //To avoid overflow
    if (low>high)
        return -1;
    if(array[mid] == number)
        return mid;
    else if(array[mid] < number)
        return binarySearchRecursive (array, mid + 1, high, number);
    else 	return binarySearchRecursive (array, low, mid - 1 , number);
    
    return -1;
}//End binarySearchRecursive 

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
    printf("\nElement %d is at location: %d", number, binarySearchRecursive(array, 0, NARRAY-1, number));
    
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n\nTime spent searching: %f\n", time_spent);
    return 0;
}//End main
