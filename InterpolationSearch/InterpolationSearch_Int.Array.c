/*********************************************************************
* Filename:  InterpolationSearch_Int.Array.c
* Author:    Javier Montenegro (www.javiermontenegro.com)
* Copyright:
* Details:   This code is the implementation of the interpolation search algorithm.
*********************************************************************/

#include <stdio.h>
#include <time.h>

#define NARRAY 10

void print(int arr[]);
int interpolationSearch(int array[], int n, int number);

int interpolationSearch(int array[], int n, int number) 
{
 int low = 0, mid, high = n-1;
 while (low <= high) {
   mid = low + (((number - array[low]) * (high - low))/(array[high] - array[low]));
     if (number == array[mid])
       return mid + 1;
     if (number < array[mid])
       high = mid - 1;
     else
       low = mid + 1;
 }//End while
 return -1;
}//End interpolationSearch

void print(int arr[])
{
 for(int i = 0; i < NARRAY; ++i)
   {
    printf("%d ", arr[i]);
   }//End for
 printf("\n");
}//End print

int main()
{
 int array[NARRAY] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};
 int number = 24;

 printf("Initial array\n");
 print(array);
 printf("\n------------\n");
    
 clock_t start = clock();
 printf("Found element %d at index: %d", number, interpolationSearch(array, NARRAY, number));

 clock_t end = clock();
 double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

 printf("\n\nTime spent searching: %f\n", time_spent);
 return 0;
}//End main