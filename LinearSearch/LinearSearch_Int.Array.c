#include <stdio.h>
#include <time.h>

#define NARRAY 11

int linearSearch(int array[], int n, int number);
void print(int arr[]);

int linearSearch(int array[], int n, int number)  
{
 for (int i  = 0; i < n; i++) {
   if (array[i] == number)
	  return i;
	else if (array[i] > number)
	  return -1;
  }//End for
  return -1;
}//End linearSearch

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
 printf("Found element %d at index: %d", number, linearSearch(array, NARRAY, number));

 clock_t end = clock();
 double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

 printf("\n\nTime spent searching: %f\n", time_spent);
 return 0;
}//End main