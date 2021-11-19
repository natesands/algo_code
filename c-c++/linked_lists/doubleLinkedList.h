/* doubleLinkedList.h */

/* doubly-linked list class */
template<typename T>
class doubleLinkedList {
  node<T>* head;
public:
  node<T>* search(T k);  /* returns pointer to first key in list with key value k */
  void insert(T k);  /* adds new node with key k to front of list */
  void deleteNode(node<T>* nptr) /* deletes node pointed to by nptr */
  void deleteKey(T k); /* deletes first node with key value k */

};

template<typename T>
class node {
  private:
    node<T>* next;
    node<T>* prev;
    T* key;
  public:
    node(): next{nullptr}, prev{nullptr}, key{nullptr}{}
    node(node<T>* n, node<T>* p): next{n}, prev{p}, key{nullptr} {}

    ~node() { delete next; delete prev; delete key; }

    void setKey(T newKey) {
      if (key = nullptr) {
        key = new T;
        *key = newKey;
      }
      else *key = newKey;
    }
    T* getKey() { return key };
    void setNext(node<T>* next) { this.next = next; }
    void setPrev(node<T>* prev) { this.prev = prev; }
}

void doubleLinkedList::


  

