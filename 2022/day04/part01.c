#include <stdio.h>

int main()
{
  int res;
  int xb, xe, yb, ye;   // x_begin, x_end...
  int count;

  FILE *fp = fopen("input.txt", "rt");

  for (count=0; res = fscanf(fp, "%d-%d,%d-%d", &xb, &xe, &yb, &ye), res != EOF;)
    if (xe>=ye && xb<=yb)
      count++;
    else if (xe<=ye && xb>=yb)
      count++;

  printf("containments: %d\n", count);

  fclose(fp);
  return 0;
}