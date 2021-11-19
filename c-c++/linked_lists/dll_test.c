#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"




int main(int argc, char **argv)
{

  dll* ll = malloc(sizeof(dll));

  if (argc < 3) return 1;
   
  node* n;
  for (int i=3; i<argc; i++) {
    n = malloc(sizeof(node));
    n->key=atof(argv[i]);
    insert(ll,n);
  }
  print(ll);
  
  dll *unsorted;

  for (int j=5; j >= 0; j--) {
    n = malloc(sizeof(node));
    n->key=(double) j;
    insert(unsorted,n);
  }
  insertion_sort(unsorted);
  print(unsorted);

  return 0; 

}


