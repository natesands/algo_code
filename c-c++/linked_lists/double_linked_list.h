/* double_linked_list.h */

/* node */

#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
  struct list_node* next;
  struct list_node* prev;
  double key;
} node;


typedef struct double_linked_list {
  node* head;
} dll;

node* search(node* nptr, double k); /* returns pointer to first node with key value k, else NULL */
node* rec_search(node* nptr, double k); /* recursive search */
void insert(dll *list, node *nptr); /* inserts node  */
int del(dll *list, double k); /* deletes first node with key value k, returns -1 if unable to find, 1 otherwise */
void print(dll *ll);
//void ll_insertion_sort(dll* list);
dll* init_dll();


node* rec_search(node* nptr, double  k) {
  if (nptr == NULL) return NULL;
  if (nptr->key == k) return nptr;
  return rec_search(nptr->next, k);
}

node* search(node* nptr, double k) {
  while (nptr->key != k && nptr != NULL) {
    nptr = nptr->next;
  }
  return nptr;
}

void insert(dll *list, node *nptr) {
  nptr->next = list->head;
  if (list->head != NULL)
    (list->head)->prev = nptr;
  list->head = nptr;
  nptr->prev = NULL;
}


int del(dll* list, double k) {
  node* loc = search(list->head, k);
  if (loc == NULL) return -1;
  if (loc->prev != NULL)
    (loc->prev)->next = loc->next;
  else (list->head = loc->next);
  if (loc->next != NULL) 
    (loc->next)->prev = loc->prev;
  return 1;
}

void print(dll *ll) {
  node *nptr = ll->head;
  while (nptr != NULL) {
    printf("%f\n",nptr->key);
    nptr = nptr->next;
  }
}

/*
void insertion_sort(dll* list)
{ 
  double k;
  node *zero_node = (node*) malloc(sizeof(node));
  zero_node->prev = NULL;
  zero_node->next = list->head;
  (list->head)->prev = zero_node;
  node *iptr;
  node *jptr = (list->head)->next;
  while(jptr != NULL ) {
    k = jptr->key;
    iptr = jptr->prev;
    while(iptr != zero_node && iptr->key > k) {
      (iptr->next)->key = iptr->key;
      iptr = iptr->prev;
    } //assert:  iptr->key <= k or iptr
      //assert:  (iptr->next)->key = iptr->key
    (iptr->next)->key = k;
    jptr = jptr->next;
  }
  (list->head)->prev = NULL;
  free(zero_node);
  zero_node = NULL;
}
*/

dll* init_dll() {
  dll* new_dll = malloc(sizeof(dll));
  new_dll->head = NULL;
  return new_dll;
}

