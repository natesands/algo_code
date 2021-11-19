#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char text[] = "Hello!";
  char src[] = "oop";
  char *text2 = "Hello?";
  printf("%s length: %lu\n", text, strlen(text));
  printf("%s size: %lu\n", text, sizeof(text));
  printf("%s length: %lu\n", text2, strlen(text));
  printf("%s size: %lu\n", text2, sizeof(text));
  strcpy(text, src);
  printf("%s length: %lu\n", text, strlen(text));
  printf("%s size: %lu\n", text, sizeof(text));
  
  printf("%s before sprintf XX\n", text);
  sprintf(text, "%s","XX");
  printf("%s after\n", text);
  printf("The length of 'FizzBuzz' is %lu\n", sizeof("FizzBuzz"));

  char fzbz[10];
  sprintf(fzbz, "FizzBuzz");
  printf("fzbz: %s\n len: %lu", fzbz, strlen(fzbz));

  char wierd[14];
  wierd = (char *) wierd;
  printf("wierd size %lu: \n %s\n", sizeof(wierd), wierd);
  *wierd=NULL;
  printf("wierd after nulling size %lu: \n %s\n", sizeof(wierd), wierd);

    

  return 0;
}

