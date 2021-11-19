#include <stdio.h>

/* strlen: return length of string */
int strlen(char *s)
{
  int n;

  for (n=0; *s != '\0'; s++)
    n++;
  return n;
}

int main()
{
  char *p;
  p = "abc";
  printf(p);
  /* is ok, but, better yet */
  printf("\n%s\n",p);

  /* 0 is ok to use rather than '\0' */
  char date[8] = "June 14";
  for (int i =0; date[i] != 0; i++)
    printf("%c",date[i]);

  for (int i =0; date[i] != '\0'; i++)
    printf("%c",date[i]);

  printf("\n%d\n",strlen(date));
  return 0;
}

