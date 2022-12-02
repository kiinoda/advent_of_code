#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define MAX_DIGITS 10

int compare_ints(const void *x, const void *y)
{
  int a = *((int*)x);
  int b = *((int*)y);
  return (a>b)-(a<b);
}

int sum(int a[3])
{
  int res = 0;
  for (int i = 0; i < 3; i++)
    res += a[i];
  return res;
}

int main()
{
  int top[3];
  int pos, cur;
  void *res;

  //% we assume that the calorie count of any food item  has no more than 10 digits
  char v[MAX_DIGITS];

  FILE *fp = fopen("input.txt", "rt");

  // init to zeros
  memset(top, 0, 3 * sizeof(int));

  //% read from file until res == NULL (EOF)
  for (cur = 0, pos = 0; res = fgets(v, MAX_DIGITS, fp), res != NULL; /* no action here */)
  {
    if (*v == '\n')
    {
      if (pos < 3)
        top[pos] = cur;
      else if (*top < cur)
      {
        if (3 == pos)
          qsort(top, 3, sizeof(int), compare_ints);
        *top = cur;
        qsort(top, 3, sizeof(int), compare_ints);
      }
      cur = 0;
      pos++;
    }
    else
      cur += atoi(v);
  }
  fclose(fp);

  printf("calories being carried by top 3: %d\n", sum(top));

  return 0;
}
