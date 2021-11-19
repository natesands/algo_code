typedef struct {
  int *q;
  int first;
  int last;
  int count;
  int size;
} queue;

void init_queue(queue *q, int size) 
{
  q->q = (int *) malloc(sizeof(int)*size);
  q->size = size;
  q->first = 0;
  q->last = size-1;
  q->count = 0;
}

void enqueue(queue *q, int x) 
{
  if (q->count >= q->size)
    printf("Warning: queue overflow enqueue x: %d\n", x);
  else {
    q->last = (q->last+1) % q->size;
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
    q->first = (q->first+1) % q->size;
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
    printf("%d\n" , q->q[ q->first + i % q->size]);
}

