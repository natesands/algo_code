#include <stdio.h>
#include <stdlib.h>  // malloc
#define QUEUESIZE 5
typedef struct {
  int q[QUEUESIZE];
  int first;
  int last;
  int count;
} queue;

void init_queue(queue *q) 
{
  q->first = 0;
  q->last = QUEUESIZE-1;
  q->count = 0;
}

void enqueue(queue *q, int x) 
{
  if (q->count >= QUEUESIZE)
    printf("Warning: queue overflow enqueue x: %d\n", x);
  else {
    q->last = (q->last+1) % QUEUESIZE;
    q->q[ q->last ] = x;
    q->count = q->count + 1;
  }
}

int dequeue(queue *q)
{
  int x;

  if (q->count <= 0) printf("Warning: empty queue dequeue.\n");
  else {
    x = q->q[ q->first ];
    q->first = (q->first+1) % QUEUESIZE;
    q->count = q->count - 1;
  }
  return x;
}

int empty(queue *q) 
{
  if (q->count <= 0) return 1;
  else return 0;
}

void print_queue(queue *q) 
{
  for (int i=0; i < q->count; i++)
    printf("%d\n" , q->q[ q->first + i % QUEUESIZE]);
}

int main() 
{
  queue *q = (queue *) malloc(sizeof(queue));
  init_queue(q);
  for (int i = 0; i < QUEUESIZE; i++)
    enqueue(q, i);
  print_queue(q);
  
  while (!empty(q)) {
    printf("dequeued: %d\n", dequeue(q));
    print_queue(q);
  }
  return 0;
}



/* queuesize  = 4
 * count = 0
 * [- - - - - ] 
 *  f     l
 * 
 * enq(1)
 * count = 1
 * [- - - - 1 ]
 *  f       l
 * 
 * enq(2)
 * count = 2
 * [2 - - - 1 ] 
 * l/f    
 *
 * deq()
 * count = 1
 * 
 * [2 - - - 1 ] 
 * l/f    
*/

