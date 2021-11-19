#define MAX_NUM_ROOT 100

typedef struct heap_node {
  struct heap_node* parent;
  struct heap_node* child; /* pointer to any child */
  struct heap_node* left;
  struct heap_node* right;
  int key;
  int degree; /* number of children */
  _Bool mark; /* set true if node has lost a child 
                since last time node was made a child
                of another node */
  /* newly created nodes are unmarked and node x becomes 
   * unmarked whenever it is made the child of another node
   */
} node;

typedef struct fh {
  node* min; /* root of any tree containing the 
                minimum tree. If fh is empty, min=NULL */
  int n; /* number of nodes in heap */
  node* root_list[MAX_NUM_ROOT];
  int num_root; /* number of root nodes */
} fib_heap;

/* the roots of all trees in a fib heap are linked together using
 * their left and right pointers in a circular, double linked list
 * call the "root list"
 */

/* POTENTIAL FUNCTION:
 * For fib heap H, t(H) = # of trees in root list of H,
 * m(H) = # marked nodes in H.  Then 
 * 
 * Phi(H) = t(H) + 2m(H)
 * Phi(Set of fib heaps H_i) = Sum(Phi(Hi))
 *
 * Assume that a unit of potential pays for a constant amount
 * of work large enough to pay for any specific constant time
 * operation
 */

/* Assume that we know an upper bound D(n) on the maximum degree of any
 * node in an n-node Fib heap. When only the mergeable-heap
 * operations are supported ,D(n) <= floor(lgn).  When 
 * we support Decrease-Ley and Delete, D(n) = O(lgn).
 */

/* Mergeable-heap operations */

/* MAKE_FIB_HEAP
 * returns fib heap object H, H.n = 0 and H.min = NIL
 * t(H)=0, m(H)=0, thus phi(H)=0 and amortized cost
 * of procedures is actual cost = O(1)
 */

fib_heap* make_fib_heap() {
  fib_heap* new_heap = (fib_heap*) malloc(sizeof(fib_heap));
  new_heap->min = NULL;
  new_heap->n = 0;
  new_heap->num_root = 0;
  return new_heap;
}

/* FIB_HEAP_INSERT(H,x)
 * inserts node x into fib heap H, assuming 
 * node has been allocated and x.key has
 * been set.
 * Amortized cost of FHI:
 * c_a = c + (t(H') + 2*m(H') - (t(H)+2*m(H))
 *     = O(1) + (t(H)+1) - t(H) = O(1)+1 = O(1);
 *        
 */
void fib_heap_insert(fib_heap *fhptr, node* nptr) {
  nptr->degree = 0;
  nptr->parent = NULL;
  nptr->child = NULL;
  nptr->mark = 0;
  fhptr->root_list[fhptr->num_root] = nptr;
  if (fhptr->min == NULL ||
      nptr->key < (fhptr->min)->key)
    fhptr->min = nptr;
  fhptr->num_root += 1;
  fhptr->n += 1;
}

/* FIND_MIN_NODE 
 * returns ptr to min node
 * c_a = 1 + 0   (since the number of nodes, and
 *                marked nodes has not changed)
 */
node* find_min_node(fib_heap *fhptr) {
  return fhptr->min;
}

/* FIB_HEAP_UNION 
 * unites fhs H1 and H2, destroying them in 
 * the process.  Concatenates the root lists of
 * H1 and H2 and determines new minimum node.
 * returns pointer to new fh.
 */
fib_heap* fib_heap_union(fib_heap* h1, fib_heap* h2) {
  int new_num_root = h1->num_root + h2->num_root;
  if (new_num_root > MAX_NUM_ROOT)
    return NULL;
  fib_heap* h_new = make_fib_heap();
  h_new->min = h1->min;
  int i,j;
  j=0;
  for (i=0; i<h1->n; i++)
    h_new->root_list[j++] = h1->root_list[i];
  for (i=0; i<h2->n; i++)
    h_new->root_list[j++] = h2->root_list[i];
  if (h1->min == NULL || (h2->min != NULL && h2->min < h1->min))
    h_new->min = h2->min;
  h_new->n = h1->n + h2->n;
  h_new->num_root = new_num_root;
  free(h1);
  free(h2);
  return h_new;
}


  
  





  
