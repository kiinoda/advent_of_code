#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define MAX_DIGITS 10
#define MAX_REINDEERS 1000
#define TOP_REINDEERS 3

int compare_ints(const void *x, const void *y)
{
  int a = *((int*)x);
  int b = *((int*)y);
  return (a>b)-(a<b);
}

int sum(int *a, int count)
{
  int res = 0;
  for (int i = 0; i < count; i++)
    res += a[i];
  return res;
}

int main()
{
  int reindeers[MAX_REINDEERS];
  int pos, cur;
  void *res;

  //% we assume that the calorie count of any food item  has no more than 10 digits
  char v[MAX_DIGITS];

  FILE *fp = fopen("input.txt", "rt");

  //% read from file until res == NULL (EOF)
  for (cur = 0, pos = 0; res = fgets(v, MAX_DIGITS, fp), res != NULL; /* no action here */)
  {
    if (*v == '\n')
    {
      reindeers[pos] = cur;
      cur = 0;
      pos++;
    }
    else
      cur += atoi(v);
  }
  fclose(fp);

  qsort(reindeers, pos, sizeof(int), compare_ints);

  //!                                           reindeers+pos-3 == &(reindeers[pos-3])
  //!                                                           |
  //!                                                           v
  printf("calories being carried by reindeers 3: %d\n", sum(reindeers+pos-3, 3));

  return 0;
}
