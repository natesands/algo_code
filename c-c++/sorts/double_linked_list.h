/* double_linked_list.h */

/* node */

#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
  struct list_node* next;
  struct list_node* prev;
  int key;
} node;


typedef struct double_linked_list {
  node* head;
} dll;

node* search(node* nptr, int k); /* returns pointer to first node with key value k, else NULL */
node* rec_search(node* nptr, int k); /* recursive search */
void insert(dll *list, node *nptr); /* inserts node  */
int del(dll *list, int k); /* deletes first node with key value k, returns -1 if unable to find, 1 otherwise */
void print(dll *ll);

node* rec_search(node* nptr, int k) {
  if (nptr == NULL) return NULL;
  if (nptr->key == k) return nptr;
  return rec_search(nptr->next, k);
}

node* search(node* nptr, int k) {
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


int del(dll* list, int k) {
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
    printf("%d\n",nptr->key);
    nptr = nptr->next;
  }
}
