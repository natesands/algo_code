/* quick-find from Sedgewick 1.3 */


#include <iostream>
using namespace std;

static const int N = 10;

int main() {
  int id[N], p, q, i;
  for (i=0; i < N; ++i) id[i]=i;
  while(cin >> p >> q) {
    int t = id[p];
    if (t == id[q]) continue; /* p and q are already connected */
    for (i=0; i < N; ++i) 
      if (id[i] == t) id[i] = id[q];
    cout << " " << p << " " << q << endl;
  }
  for (auto x : id) cout << x << " ";
  cout << endl;
}

