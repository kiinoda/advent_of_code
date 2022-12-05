#include <stdio.h>

#define MAX_SECTIONS 100

int main()
{
  int res;
  int xb, xe, yb, ye;   // x_begin, x_end...
  int i;
  int overlaps;
  int imprinter[MAX_SECTIONS];

  FILE *fp = fopen("input.txt", "rt");

  for (overlaps=0; res = fscanf(fp, "%d-%d,%d-%d", &xb, &xe, &yb, &ye), res != EOF;)
  {
    //reset imprinters
    for (i=0; i<MAX_SECTIONS; i++)
      imprinter[i] = 0;
    for (i=xb; i<=xe; i++)
      imprinter[i]++;
    for (i=yb; i<=ye; i++)
      imprinter[i]++;
    for (i=0; i<MAX_SECTIONS; i++)
      if (2==imprinter[i])
      {
        overlaps++;
        break;
      }
  }

  printf("overlaps: %d\n", overlaps);

  fclose(fp);
  return 0;
}