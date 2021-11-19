/*-------------------------------------------------------------------------------
Sorting functions.
--------------------------------------------------------------------------------*/
#include <assert.h>
#include <stdlib.h>

/* sorts a list of numbers in ascending order, odd numbers first */
void SortOddEven( int* numbers, int count )
{
  /* The general strategy is to move all odds to the left, and
   * all evens to the right, and then sort each bunch individually
   * using plain old insertion sort in O(n^2).
   */
  if ( numbers == NULL || count < 0)
    exit(0);

  int i, j, k;
  int n;
  i=0;j=0;
  // invariant: numbers[0...i-1] are odd, numbers[i..j-1] are even.
  while (i < count && numbers[i] % 2 != 0) i++;
  j=i+1;
  while (j < count) {
    if (numbers[j] %2 !=0) {
      n = numbers[j];
      numbers[j] = numbers[i];
      numbers[i] = n;
      i++;
    }
    j++;
  }
  for (int k=0; k<i; k++)
    assert(numbers[k] % 2 != 0);
  for (int k=i; k<count; k++)
    assert(numbers[k] %2 ==0); 

  /* sort odds */
  for (k=1; k<i; k++) {
    n = numbers[k];
    j = k-1;
    while (j>=0 && numbers[j] > n) {
      numbers[j+1] = numbers[j];
      j--;
    }
    numbers[j+1] = n;
  }
  /* sort evens */
  for (k=i; k<count; k++) {
    n = numbers[k];
    j = k-1;
    while (j>=i && numbers[j] > n) {
      numbers[j+1] = numbers[j];
      j--;
    }
    numbers[j+1] = n;
  }
}

void insertionSort(int *A, int count) {
  /* inv: A[1..j-1] are sorted */
  int i, j;
  int key;
  for (j=1; j<count; j++) {
    key = A[j];
    i = j-1;
    while (i >= 0 && A[i] > key) {
      A[i+1] = A[i];
      i--;
    }
    A[i+1] = key;
  }  
}
template <typename T>
void swap(T *A, int i, int j) {
  T temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}
/* Selection Sort */
template <typename T>
void selectionSort(T *A, int l, int r) {
  int i,j, min;
  for (i=0; i<r; i++) {
    min=i;
    for (j=i+1; j<=r; j++) {
      if (A[j] < A[min]) 
        min = j;
    }
    swap(A, i, min);
  }
} 

/* Quick Sort */

/* The partitioning process rearranges the array to make
 * the following conditions hold:
 * 1) The element a[i] is in its final position in the array for
 * some i
 * 2) None of the elements a[l...i-1] is greater than a[i]
 * 3) None of the elements a[i+1..r] is less than a[i]
 *
 * Here a[l] is chosen as the pivot.  
 */
template <typename T> int partition(T*,int,int);

template <typename T>
void quicksort(T *a, int l, int r) 
{
  int i;
  if (r<=l) return;
  i = partition(a, l, r);
  quicksort(a, l, i-1);
  quicksort(a, i+1, r);     //A[i] is sorted
}

template <typename T>
int partition(T *a, int left, int right) {
  int i, last;
  last = left; 
  for (i = left+1; i <= right; i++)
    if (a[i] < a[left])
      swap(a, ++last, i);
  swap(a, left, last);  
  return last;
}
    

  

  
