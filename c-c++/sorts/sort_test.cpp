#include <stdio.h>
#include "sorts.h"
#include <time.h>
#include <stdlib.h>

#define N 10
int main() {
  srand(time(NULL));
  int A[N], B[N], i;
  for (i=0; i< N; i++) A[i] = rand() % 100-50;

  printf("A:\n");
  for (i=0; i<N-1; i++)
    printf("%d ", A[i]);
  printf("%d\n", A[N-1]);
  printf("----------\n");

  printf("Insertion Sort:\n");
  for (i=0; i<N; i++) B[i] = A[i];
  insertionSort(B, N);
  for (i=0; i<N-1; i++)
    printf("%d ", B[i]);
  printf("%d\n", B[N-1]);
  printf("----------\n");
  printf("Sort Odd-Even:\n");
  for (i=0; i<N; i++) B[i] = A[i];
  SortOddEven(B, N);
  for (i=0; i<N-1; i++)
    printf("%d ", B[i]);
  printf("%d\n", B[N-1]);
  printf("----------\n");
  printf("Selection Sort:\n");
  for (i=0; i<N; i++) B[i] = A[i];
  selectionSort(B, 0,N-1);  // here selection sort takes left, right vals
  for (i=0; i<N-1; i++)
    printf("%d ", B[i]);
  printf("%d\n", B[N-1]);
  printf("----------\n");
  printf("Quicksort:\n");
  for (i=0; i<N; i++) B[i] = A[i];
  quicksort(B, 0,N-1);  // here quicksort takes left, right vals
  for (i=0; i<N-1; i++)
    printf("%d ", B[i]);
  printf("%d\n", B[N-1]);
  printf("----------\n");
  return 0;
  
}

