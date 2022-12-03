#include <stdio.h>
#include <stdlib.h>

#define MAX_ROUNDS    5000
#define ROUND_DIGITS  2
#define ROW_DIGITS    5

int xyz_vs_abc(char round[ROUND_DIGITS])
{
  if ('A' == round[0] && 'X' == round[1])
    return 1 + 3; // draw, you have rock
  if ('A' == round[0] && 'Y' == round[1])
    return 2 + 6; // win, you have paper
  if ('A' == round[0] && 'Z' == round[1])
    return 3 + 0; // lose, you have scissors
  if ('B' == round[0] && 'X' == round[1])
    return 1 + 0; // lose, you have rock
  if ('B' == round[0] && 'Y' == round[1])
    return 2 + 3; // draw, you have paper
  if ('B' == round[0] && 'Z' == round[1])
    return 3 + 6; // lose, you have scissors
  if ('C' == round[0] && 'X' == round[1])
    return 1 + 6; // win, you have rock
  if ('C' == round[0] && 'Y' == round[1])
    return 2 + 0; // lose, you have paper
  if ('C' == round[0] && 'Z' == round[1])
    return 3 + 3; // draw, you have scissors
  return 0; //! make compiler not issue a warning
}

int main()
{
  char rounds[MAX_ROUNDS][ROUND_DIGITS];
  char buf[ROW_DIGITS+1];
  void *res;
  int pos, size;
  int score;

  FILE *fp = fopen("input.txt", "rt");

  //% read from file and store in rounds[] until res == NULL (EOF)
  for (pos = 0, score=0; res = fgets((char*)&buf, ROW_DIGITS, fp), res != NULL; pos++)
  {
    rounds[pos][0] = buf[0];
    rounds[pos][1] = buf[2];
    score += xyz_vs_abc(rounds[pos]);
  }
  fclose(fp);

  printf("score: %d\n", score);

  return 0;
}
