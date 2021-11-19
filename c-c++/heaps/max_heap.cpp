// MAX-HEAP (VECTOR-BASED)
// Max-heap property: A[parent(i)] >= A[i]

#include <iostream>
using namespace std;

void max_heapify(vector<int> v, int i, int n);
void build_max_heap(vector<int> v);
void heapsort(vector<int> v);

#define left(i) 2*i
#define right(i) 2*i+1
#define parent(i) i/2

/*
 * Max-heapify assumes left and right 
 * sub-trees rooted at v[i] are max-heaps.
 * Runs in O(logn) = O(h).
 */
void max_heapify(vector<int> v, int i, int n) {
	int l = left(i);
	int r = right(i);
	int max = i;
	if (l < n && v[max] < v[l])
		max = l;
	if (r < n && v[max] < v[r])
		max = r;
	v.swap(i,max);
	if (max != i)
		max_heapify(v, max,n);
}

/*
 * Turn array into a max heap.
 * It can be shown that the run time
 * is O(n).
 */
void build_max_heap(vector<int> v) {
	size_t last_node = v.size() - 1;
	for (size_t i = parent(last_node); i >= 0; i--) {
		max_heapify(v, i, v.size());
	} 
}

/*
 * Sorts n-element array in O(nlogn)
 */
void heapsort(vector<int> v) {
	build_max_heap(v);
	int n = v.size();
	while (n > 1){
		v.swap(0, n-1);
		--n;
		max_heapify(v,0,n);
	}
}

