/* prime number class */


#include <iostream>
using namespace std;

bool isPrime(int num);

class Prime
{
public:
  Prime() :p(1){}
  Prime(int n);
  int get() { return p; }
  Prime operator++();
  Prime operator--(); 
private:
  int p;

};


Prime::Prime(int n)
{
  if (isPrime(n)) p = n;
  else
  {
    cout << "number is not prime..." << endl;
    p = 1;
  }
}

Prime Prime::operator++()
{
  
  int nextPrime = p;
  if (nextPrime < 0) nextPrime *= -1;
  nextPrime += 2;
  while (!isPrime(nextPrime))
  {
    nextPrime += 2;
  }

  p = nextPrime;

  return Prime(nextPrime);
}
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
  Prime p1(8),p2(7);
  cout << p1.get() << " " << p2.get() << endl;
  cout << endl;
  ++p1;
  ++p2;
  cout << p1.get() << " " << p2.get() << endl;

  return 0; 
}
