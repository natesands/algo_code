#include <stdlib.h>
#include "fib_heap.h"

int main() {
  fib_heap *h1 = make_fib_heap();
  node n1;
  n1.key = 10;
  fib_heap_insert(h1,&n1);
  
  fib_heap *h2 = make_fib_heap();
  node n2;
  n2.key = 20;
  fib_heap_insert(h2,&n2);

  fib_heap *h_new;
  h_new = fib_heap_union(h1,h2);

  return 0;
}

