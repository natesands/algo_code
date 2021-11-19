/* Determine if num is a prime */

#include <iostream>
using namespace std;

bool isPrime(int num)
{
  if (num < 0) num=-num;  //include neg primes
  if (num == 1 || num == 0) return false;
  if (num == 2) return true;
  if (num % 2 == 0) return false;
  for (int k=1; 2*k+1 <  num/2; k++)
  //if number is factorable, no factor
  //will be bigger than half the number
  {
    if (num % (2*k+1) == 0) return false;
  }
  return true;
}

int main()
{

  //print primes first 1000 

  int count;
  for (int i=1; i < 7920; i++)
  {
    if (isPrime(i))
    {
      cout << i << "\t";
      count ++;
      if (count % 10 == 0)
      {
        cout << endl;
      }
    }
  }
  cout << endl;

  return 0;
}
  
