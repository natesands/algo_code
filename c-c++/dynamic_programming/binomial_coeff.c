/* calculates nCk(n,k) using non-recursive tabular method and prints table
 *  
 * Run time is theta(n*k).  Notice this can be done using a one-dim
 * array representing the current row.  Storage is theta(k)
 */

/* recurrence relation:
 * nCk(n,k) = 1                         , k=0 or n=0
 *          = nCk(n-1, k-1) + nCk(n-1,k)  , 0 < k < n
 *          = 0                           , otherwise
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE  1000

int nCk(n,k) {
  if (n > MAX_SIZE) return -1;

  int *results = (int *) malloc(k*sizeof(int));
  int *row = (int *) malloc(k*sizeof(int));
  for (int i=0; i<=n;i++) {
    for (int j=0; j <= k; j++) {
      if (j == 0 || j == i)
        row[j] = 1;
      else if (j > 0 && j < i)
        row[j] = results[j] + results[j-1];
      else
        row[j] = 0;
      printf("%d\t ", row[j]);
    }
    printf("\n");
    free(results);
    results = row;
    row = (int *) malloc(sizeof(int)*k);
     
  }
  return results[k];
}


int main(int argc, char** argv) {
  if (argc < 3) {
    printf("Usage: nCk n k");
    return 1;
  }
  printf("\nresult: \t%d\n",nCk(atoi(argv[1]), atoi(argv[2])));
  return 0;
      
}
  

/*
int nCk(n, k){
  if (n > MAX_SIZE) return 1;
  int results[n][k];

  for (int i=0; i<=n; i++)
    for (int j=0; j<=k; j++) {
      if (n == 0 || k == 0) 
        results[i][j] = 0;
      if (0 < i && j < i)
        results[i][j] = results[i-1][j-1] + results[i-1][j];
      else
        results[i][j] = 0;
    }

  return results[n][k];
}

*/
