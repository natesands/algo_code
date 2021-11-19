// Queue.h
// Uses an array Q[0..n-1] to store at most n-1 elements.
// Elements of queue reside in locations
// Q.head, Q.head+1, ..., Q.tail-1.
// When Q.head==Q.tail, the queue is empty.
// When Q.head==Q.tail+1, the queue is full.
// We start with Q.head=Q.tail=0; 
// enqueue and dequeue take O(1).

class Queue {
public:
  Queue(int n);
  void enqueue(int c);
  int dequeue();
private:
  int* Q;
  int length;
  int head; // index of head
  int tail; // index of next location for enqueue
};

void error(std::string s) {
  throw std::runtime_error(s);
}

Queue::Queue(int n)
  : head(0), tail(0), length(n)
{
  Q = new int[n];
}

void Queue::enqueue(int x)
{
  int next = (tail + 1) % length;
  if (next == head) error("Queue overflow.");
  Q[next] = x;
  tail = next;
}

int Queue::dequeue()
{
  if (head==tail) error("Queue empty.");
  int x = Q[head];
  head = (head + 1) % length;
  return x;
}




