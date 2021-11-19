/* simulates card game WAR */
#include <stdio.h>
#include "/Users/ironchefnate/iCloud/Documents/cs/pl/code/data_strutures/queues/queue_v0.h"
#define NCARDS 52
#define NSUITS 4
#define TRUE 1
#define FALSE 0
#define MAXSTEPS NCARDS*5
void war(queue *a, queue *b);

char values[] = "23456789TJQKA";
char suits[] = "cdhs";



/* assign each card a unique integer 0 to 51 */
int rank_card(char value, char suit) {
  int i, j;

  for (i = 0; i < NCARDS/NSUITS; i++)
    if (values[i] == (char) value)
      for (j = 0; j<NSUITS; j++)
        if (suits[j] == suit)
          return i*NSUITS + j;
  printf("Warning: bad input value=%d, suit%d\n", value, suit);
  return -1;

    /* NOTE:  Think of a matrix whose rows correspond to 
     * the face values and whose columns correspond to
     * the suits.  Each entry is numbered sequentially
     * left to right, up down, from 0 to 51.
     * How do you calculate the i,j th entry?
     */
}

char suit(int card) 
{
  return suits[ card % NSUITS ];
}

char value(int card) {
  return values[ card/NSUITS ];
}

int main() 
{

  queue decks[2];
  char value, suit, c;  /* input characters */
  int i;

  while(TRUE) {
    for (i=0; i <= 1; i++) {
      init_queue(&decks[i], NCARDS/2);

      while (c = getchar() != '\n') {
        if (c == EOF) return;
        if (c != ' ') {
          value = c;
          suit = getchar();
          enqueue(&decks[i], rank_card(value,suit));
        }
      }
    }

    war(&decks[0], &deck[1]);
  }
  return 0;
}

void war(queue *a, queue *b) 
{
  int steps = 0;
  int x, y;
  queue c;
  bool inwar;

  inwar = FALSE;
  init_queue(&c, NCARDS);

  while((!empty(a)) && (!empty(b) && (steps < MAXSTEPS))) {
    ++steps;
    x = dequeue(a);
    y = dequeue(b);
    enqueue(&c,x);
    enqueue(&c,y);
    if (inwar) {
      inwar = FALSE;
    } else {
      if (value(x) > value (y))
        clear_queue(&c,a);
      else if (value(x) < value(y))
        clear_queue(&c, b);
      else if (value(y) == value(x))
        inware = TRUE;
    }

  
