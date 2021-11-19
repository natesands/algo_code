// implements stack of at most n elements
// using an array S  
// attribute S.top indexes most recently inserted element
// S[1] is bottom element, S[S.top] is element at top.


#include <iostream>

class Stack {
public:
  Stack(int n);
  ~Stack() {delete [] S;}

  bool stack_empty() { return top == -1; }
  bool stack_full() { return top == size-1; }
  void push(int x); 
  int pop();
  int getSize() { return size; }
private:
  void resize();
  int top; 
  int size;
  int* S;
};

Stack::Stack(int n)
{
//pre : n > 0
  S = new int[n];
  top = -1;
  size = n;
}

void Stack::push(int x) 
{
  if (stack_full())
    this->resize();
  S[++top] = x;
}

int Stack::pop() 
{ 
  if (stack_empty()) { 
    std::cout << "stack empty";
  }
  else
    return S[top--]; 
}

void Stack::resize()
//pre: top = size - 1
{
  int* temp = new int[2*size];
  for (int i=0; i < size; i++)
    temp[i] = S[i];
  delete [] S;
  S = temp;
  size *= 2;
}
