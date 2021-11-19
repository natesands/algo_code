#include <iostream>
using namespace std;

typedef int * IntArrPtr;
int main() {

  int n,q;
  cin >> n >> q;

  IntArrPtr* a = new IntArrPtr[n];
  //populate array
  for (int i=0; i < n; i++) {
    int k;
    cin >> k;
    a[i] = new int[k];
    for (int j = 0; j < k; j++) {
      cin >> a[i][j];
    }
  }
  //handle queries
  int i,j;
  for (int qry = 0; qry < q; qry++) {
    cin >> i >> j;
    cout << a[i][j] << endl;
  }

return 0;
}

