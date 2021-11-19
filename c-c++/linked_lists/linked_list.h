/* linked list */

#include <iostream>

template <typename T>
struct node { 
  T item; 
  node* next;
  node (T x, node *t) :item(x), next(t) { }
  node() : item (), next(nullptr) {}
};

template <typename T>
using link = node<T> *;

template <typename T>
int count_nodes_in_circular_list(link<T> l) {
  int i;
  for (i=1;l->next != l; i++, l=l->next);
  return i;
} 

template <typename T>
link<T> rec_append(link<T> l1, link<T> l2) {
  if (l1->next == nullptr) {
    l1->next = l2;
    return l1;
  }
  else {
    l1->next = rec_append(l1->next, l2);
    return l1;
  }
}

template <typename T>
link<T> append(link<T> l1, link<T> l2) {
  link<T> x = l1;
  while(x->next != nullptr) x=x->next;
  x->next = l2;
  return l1;
}

template <typename T>
link<T> rec_reverse(link<T> l) {
  if (l->next == nullptr)
    return l;
  link<T> tmp = l->next;
  l->next = nullptr;
  return append(rec_reverse(tmp), l);
}

template <typename T>
link<T> reverse(link<T> l) {
  link<T> t, y = l, r = nullptr;
  while (y != nullptr)
  { t=y->next;
    y->next = r; 
    r = y;
    y = t;
  }
  return r;
}

template <typename T>
std::string list_to_str(link<T> l) {
  std::string s;
  while (l != nullptr) {
    s = s + std::to_string(l->item) +  " ";
    l = l->next;
  }

  return s;
}

template <typename T>
link<T> list_insertion_sort(link<T> a) {
  link<T> z, u, x, b;
  /* invariant:  
   * list b contains the nodes of a, up to
   * but not including the node pointed to by t, in sorted order
   */
  t = a;  /* everything from t on is unsorted */
  while (t != nullptr) {
    u = t->next;
    x = b;
    while(x->next != nullptr && x->next->item <= t->item)
      x = x->next;
    /* assert: x->next == nullptr or x->next->item > t->item */
    t->next = x->next;
    x->next = t;
    t = u;
  }
  return b;
}


