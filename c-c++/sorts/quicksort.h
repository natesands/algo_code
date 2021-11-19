/* Quicksort */
/* quicksort.h */
void quicksort(int *A, int left, int right);
int partition(int *A, int left, int right);

void quicksort(int *A, int left, int right)
{
  int q;
  if (left < right) {
    q = partition(A, left, right);
    quicksort(A, left, q-1);
    quicksort(A, q+1, right);
  }
}


int partition(int *A, int left, int right)
/* pre: left < right
 * post: returns int q s.t. A[0..q-1] < A[q..right]
 */
{
  int i, j, pivot, temp;
  
  i = left-1;
  j = left;
  pivot = A[right];
  while(j < right) {
    if (A[j] <= pivot) {
      i += 1;
      temp = A[j];
      A[j] = A[i];
      A[i] = temp;
    }
    j++;
  }
  i++;
  temp = A[i];
  A[i] = A[right];
  A[right] = temp;
  return i;
}
