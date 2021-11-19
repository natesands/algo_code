#include <iostream>
using namespace std;
static const int N = 1000;

int main()
{
  int i, a[N];
  for (i=2; i<N; i++) a[i]=1;
  for (i=2; i<N; i++)
    if (a[i]) 
      for (j =i; j*i <N; j++) a[j*i] = 0;
  for (i=2; i < N; i++)
    if (a[i]) cout << " " << i;
  cout << endl;
}
