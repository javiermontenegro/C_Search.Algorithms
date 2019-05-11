#include <stdio.h>
#include <math.h>
#include <time.h>

#define min(X,Y) ((X) < (Y) ? (X) : (Y))  
#define NARRAY 16

void print(int arr[]);
int jumpSearch(int* array, int number, int n);

int jumpSearch(int* array, int number, int n) 
{
 int step = floor(sqrt(n));
 int prev = 0;
 
 while (*(array + (min(step, n) - 1)) < number)  
 {
  prev = step;
  step += floor(sqrt(n));
  if (prev >= n)
    return -1;
 }//End while

 while (*(array + prev) < number) 
 {
  prev = prev + 1;
  if (prev == fmin(step, n))
    return -1;
 }//End while

 if (*(array + prev) == number)
   return prev;
 
 return -1;
}//End jumpSearch

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
 int array[NARRAY] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
 int number = 144;

 printf("Initial array\n");
 print(array);
 printf("\n------------\n");
    
 clock_t start = clock();
 printf("Found element %d at index: %d", number, jumpSearch(array, number, NARRAY));

 clock_t end = clock();
 double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

 printf("\n\nTime spent searching: %f\n", time_spent);
 return 0;
}//End main

