/* quick-find from Sedgewick 1.3 */


#include <iostream>
using namespace std;

static const int N = 10;

int main() {
  int id[N], p, q, i,j;
  for (i=0; i < N; ++i) id[i]=i;
  while(cin >> p >> q) {
    for (i = p; i != id[i]; i = id[i]);
    for (j = q; j != id[j]; j = id[j]);
    if (i == j) continue;
    id[i] = j;
    cout << " " << p << " " << q << endl;
  }
  for (auto x : id) cout << x << " ";
  cout << endl;
}

