#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define MAX_DIGITS 10

int main()
{
  int max, cur;
  //% we assume that the calorie count of any food item  has no more than 10 digits
  char v[MAX_DIGITS];
  void *res;

  FILE *fp = fopen("input.txt", "rt");

  //% read from file until res == NULL (EOF)
  for (max = 0, cur = 0; res = fgets(v, MAX_DIGITS, fp), res != NULL; /* no action here */)
  {
    if (*v == '\n')
    {
      if (max < cur)
        max = cur;
      cur = 0;
    }
    else
      cur += atoi(v);
  }
  fclose(fp);

  printf("max calories being carried: %d\n", max);

  return 0;
}
