#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

/* Bit manipulation */


/* Length of binary word. Length(0) := 1 */
int lengthWord(unsigned int x) {
  int length = 0;
  if (x == 0 )
    return 1;
  while (x) {
    x >>= 1;
    length++;
  }
  return length;
}

/* Int to binary string */
string bitString(unsigned int x) {
  string result;
  do result.push_back('0' + (x & 1));  // NB
  while (x >>= 1);

  reverse(result.begin(), result.end());
  while (result.size() % 8 != 0)
    result.insert(0,1,'0');
  return result;
}

/* Print binary rep of number */
void printBits(unsigned int x) {
  if (x == 0)
    return;
  printBits(x >> 1);
  printf("%d", x & 1);
}

/* Bit at ith postion (rightmost bit is 0th) */
int ithBit(unsigned int x, int i) {
 return x & (int) pow(2,i);
} 

/* Count 1 bites in unsigned int */
int countSetBits(unsigned int n) {
  int num_set_bits = 0;
  while (n) {
    num_set_bits += n & 1;
    n >>= 1;
  }
  return num_set_bits;
}

/* Parity of a binary word */
int wordParity(unsigned long x) {
  short parity = 0;
  while (x) {
    parity ^= (x & 1);
    x >>= 1;
  }
  return parity;
}

/* return right-most 1 bit */
int rightMostBit(unsigned long x) {
  return x & ~(x-1);
}

/* return left-most set bit */
int leftMostBit(unsigned long x) {
  int power = 0;
  if (x == 0) 
    return 0;
  while(x) {
    x >>= 1;
    power++;
  }
  return pow(2, power);
}


/* replace right-most 1 bit with 0 */
int replaceRightMostBit(unsigned long x) {
  return x & (x-1);
}

/* right-propogate right-most set bit */
int rightPropRightBit(unsigned long x) {
  return x | (x-1);
}

int main() {
  for (int i=0; i<20; i++)
    printf("%s\n", bitString(i).c_str());
  return 0;
}


