#include "Stack.h"

int main() {

  Stack s(4);


  
  for (int i=0; i<20; i++)
    s.push(i);
  std::cout << "size is: " << s.getSize() << std::endl; 
  for (int i=0; i<20; i++)
    std::cout<<s.pop();
  std::cout << std::endl;
  return 0;
}

