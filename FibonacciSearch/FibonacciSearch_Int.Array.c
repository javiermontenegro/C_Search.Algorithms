/*********************************************************************
* Filename:  FibonacciSearch_Int.Array.c
* Author:    Javier Montenegro (www.javiermontenegro.com)
* Copyright:
* Details:   This code is the implementation of the fibonacci search algorithm.
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NARRAY 11

void print(int arr[]);
int fibMonaccianSearch(int arr[], int x, int n);

int fibMonaccianSearch(int arr[], int x, int n)
{    /* Initialize fibonacci numbers */
  int fibMMm2 = 0;   // (m-2)'th Fibonacci No.
  int fibMMm1 = 1;   // (m-1)'th Fibonacci No.
  int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci

  while (fibM < n)
    {
     fibMMm2 = fibMMm1;
     fibMMm1 = fibM;
     fibM  = fibMMm2 + fibMMm1;
    }//End while

  int offset = -1;
  while (fibM > 1)
    {
     int i = ((offset+fibMMm2) < (n-1)) ? (offset+fibMMm2) : (n-1);

     if (arr[i] < x)
       {
        fibM  = fibMMm1;
        fibMMm1 = fibMMm2;
        fibMMm2 = fibM - fibMMm1;
        offset = i;
       }
     else if (arr[i] > x)
       {
        fibM  = fibMMm2;
        fibMMm1 = fibMMm1 - fibMMm2;
        fibMMm2 = fibM - fibMMm1;
       }
      else return i;
    }//End while

    if(fibMMm1 && arr[offset+1]==x)return offset+1;
    
    return -1;
}//End fibMonaccianSearch 

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
 int array[NARRAY] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
 int number = 85;

 printf("Initial array\n");
 print(array);
 printf("\n------------\n");
    
 clock_t start = clock();
 printf("Found element %d at index: %d", number, fibMonaccianSearch(array, number, NARRAY));

 clock_t end = clock();
 double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

 printf("\n\nTime spent searching: %f\n", time_spent);
 return 0;
}//End main
