// 'FizzBuzz' is a game in which people take turns saying increasing numbers, but sometimes
// they have to say a word instead of a number.
// Write a function which:
// - Takes an integer. E.g. 2
// - Normally writes the integer as a string to the buffer pointed to by 'output'. E.g. "2"
// - If a multiple of 3 is passed, writes "Fizz" to the buffer pointed to by 'output', instead of printing the number.
// - If a multiple of 5 is passed, writes "Buzz" to the buffer pointed to by 'output', instead of printing the number.
// - If a multiple of both 3 and 5 is passed, writes "FizzBuzz" to the buffer pointed to by 'output', instead of printing the number.
// You may use strcpy and sprintf if you wish. You may look at the following two links for their definition if needed:
//    http://msdn.microsoft.com/en-us/library/kk6xf663(VS.90).aspx
//    http://msdn.microsoft.com/en-us/library/ybk95axf(VS.90).aspx

#include <stdio.h>
#include <stdlib.h>

void FizzBuzz( int value, char *output)
{
  
  if (value % (3*5) == 0)
    sprintf(output, "Fizzbuzz");
  else if (value % 5 == 0) 
    sprintf(output, "Buzz");
  else if (value % 3 == 0)
    sprintf(output, "Fizz");
  else
    sprintf(output,"%d", value);
}

int main() {
  char temp[16];
  for (int i=-20; i<20; i++) {
    FizzBuzz(i, temp);
    if( *temp )
      printf( "%d: %s\n", i, temp );
    printf("%d mod 2 = %d", i, i%2);
      
  }

  return 0;
}
