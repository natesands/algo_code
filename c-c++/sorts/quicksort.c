#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

int main(int argc, char **argv)
{ 
  int q;
  if (argc == 1) return 1;
  int size = argc-1;
  int A[size];
  for (int i=1; i<=size; i++)
    A[i-1] = atoi(argv[i]);
  quicksort(A,0,size-1);
  for (int i=0; i<size; i++)
    printf("%d ", A[i]);
  printf("\n");
  return 0;
}


