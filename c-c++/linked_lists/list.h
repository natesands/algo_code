/* template class for linked lists */

#include <iostream>
#include <memory>
#include <cassert>


/* NODE */
template<typename T>
struct node {
  node(T d) : data(d) {}
  node() = default;
  T data;
  std::shared_ptr<node<T>> next; // will be initialized to 
  std::shared_ptr<node<T>> prev;
};

/* LIST CLASS */
template <typename T> class List {
public:
   using size_type = unsigned long;

   List(T d) : head{ std::make_shared<node<T>>(d) }, sz{1},
     tail{std::make_shared<node<T>>()}
   {
     head->next = tail;
     tail->next = nullptr;
   }

   List() : head{nullptr}, tail{nullptr}, sz{0}  {}
   void insert(T key);
   void print();

   class iterator;
   iterator begin() {return iterator(head);}
   iterator end() {return iterator(tail);}
   iterator insert(iterator p, const T& v);  // insert v into list after p
   iterator erase(iterator p);               // remove p from the list
   
   size_type size() { return sz; }

   void push_back(const T& v);
   void push_front(const T& v);
   void pop_front();
   void pop_back();
   
   T& front();
   T& back();
private:
   std::shared_ptr<node<T>> head;
   std::shared_ptr<node<T>> tail;
   size_type sz;
};

// template<typename T>
// List<T>::iterator List<T>::insert(List<T>::iterator p, const T& v) {
//   auto new_node = std::make_shared<node<T>>(v);
//   new_node->next = p.curr->next;
//   p.curr->next = new_node;
//   return List<T>::iterator(new_node);
// }

template<typename T>
class List<T>::iterator {
  std::shared_ptr<node<T>> curr;  // current node
public:
  iterator(std::shared_ptr<node<T>> p) : curr{p} {}
  
  iterator& operator++() {curr = curr->next; return *this;}
  bool operator==(const iterator& b) const {return curr==b.curr; }
  bool operator!=(const iterator& b) const {return curr!=b.curr;}
  T& operator*() { return curr->data; }
};


/* LIST CLASS methods */
template <typename T>
void List<T>::insert(T key) {
  if (sz == 0) {
    head = std::make_shared<node<T>>(key);
    sz++;
  }
  else {
     
    std::shared_ptr<node<T>> p = head;
    while(p->next) 
      p = p->next;
    p->next = std::make_shared<node<T>>(key);
    sz++;
  }
}
/*
template <typename T>
void List<T>::push_back(const T& v) {
  List<T>::iterator 
 */ 

template <typename T>
void List<T>::print() {
  for (List<T>::iterator iter = this->begin(); iter != this->end(); ++iter)
  //  for (auto iter : *this)
    std::cout << *iter << " ";
  std::cout << '\n';
}

/* Node-based functions 
 * list_search
 * list_insert
 * list_insert_after
 * delete_after
 * print_list
 * merge_lists
 */


template <typename T>
std::shared_ptr<node<T>> list_search(std::shared_ptr<node<T>> p, T key) {
  while(p && p->data != key)
    p = p->next;
  return p;
}

template <typename T>
std::shared_ptr<node<T>> list_insert(std::shared_ptr<node<T>> ptr, T key) {
  // assumes ptr is head of list; inserts before ptr
  auto new_node_ptr = std::make_shared<node<T>>();
  new_node_ptr->data = key;
  new_node_ptr->next = ptr;
  return new_node_ptr;
}

template <typename T>
void list_insert_after(std::shared_ptr<node<T>> n, std::shared_ptr<node<T>> new_node) {
  new_node->next = n->next;
  n->next = new_node;
}

template <typename T>
void list_delete_after(std::shared_ptr<node<T>> p) {
  assert(p && p->next); // p is not a tail  
  p->next = p->next->next;
}

template <typename T>
void print_list(std::shared_ptr<node<T>> l) {
  if (l == nullptr)
    std::cout << "\n";
  else {
    std::cout << l->data << " ";
    print_list(l->next);
  }
}


template <typename T>
std::shared_ptr<node<T>> merge_lists(std::shared_ptr<node<T>> a, std::shared_ptr<node<T>> b) {
  assert(a && b); // neither list is null
  std::shared_ptr<node<T>> tmp_ptr;
  
  // while loop inv:  a->data <= b->data
  if (a->data > b->data) {
    tmp_ptr = b;
    b = a;
    a = tmp_ptr;
  }
  std::shared_ptr<node<T>> merged_list = a;
  while (a->next && b)
  {
    if (b->data < a->next->data) {
      tmp_ptr = b->next;
      list_insert_after(a, b);
      b = tmp_ptr;
    }
    a = a->next;
  }
  if (a->next == nullptr) {
    a->next = b;
  }
  return merged_list;
}

template <typename T>
std::shared_ptr<node<T>> reverse_list(std::shared_ptr<node<T>> p) {
  // inv:  curptr->next != nullptr
  // curptr is head of linked list and p is tail
  std::shared_ptr<node<T>> curptr, prevptr, tmp; 
  curptr = tmp = p;
  prevptr = nullptr;
  while(curptr->next != nullptr) {
    tmp = curptr->next;
    curptr->next = prevptr;
    prevptr = curptr;
    curptr = tmp;
  }
  curptr->next = prevptr;
  return curptr;
}


