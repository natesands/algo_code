#include <iostream>
#include "Queue.h"

using namespace std;

void skip_to_int()
{
  if (cin.fail()){
    cin.clear();
    for (char ch; cin >> ch; ) {
      if (isdigit(ch)){
        cin.unget();
        return;
      }
    }
  }
  error("no input");
} 
    
int main()
{
  
  int n = 0;
  cout << "Enter size of queue: \n";
  cin >> n;
  while (!cin) {
     cout << "Please enter an integer...\n";
     cin.clear();
     for (char ch; cin >> ch;) {
      if (isdigit(ch)) {
        cin.unget();
        cin >> n;
        break;
      }
     } 
  }

  cout << "You entered " << n << endl;
  Queue q = Queue{n};
  
  return 0;

}  

