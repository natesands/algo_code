#include <stdio.h>
#include <stdlib.h>  // malloc
#include "queue_v0.h"

int main() 
{
  const int queue_size = 52; 
  queue q;
  init_queue(&q,queue_size);
  for (int i = 0; i < queue_size; i++)
    enqueue(&q, i);
  print_queue(&q);
  
  while (!empty(&q)) {
    printf("dequeued: %d\n", dequeue(&q));
    print_queue(&q);
  }
  return 0;
}
