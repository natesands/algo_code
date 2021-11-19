#include <stdio.h>


/* Pointer arithmetic */
void printString(char *a) {
  char *p = a;
  while (*p != '\0')
    printf("%c", *p++);
}

int main() {
  char *msg = "Hello!";
  printString(msg);
}


