#include <stdio.h>

#define MAX_ITEMS 127
#define MAX_HASH_ELEMENTS 128

int main()
{
  int fake_hash[MAX_HASH_ELEMENTS];
  char buf[MAX_ITEMS];
  int i, j, pos, buf_count, score, total_score;
  char *res;

  total_score = 0;

  FILE *fp = fopen("input.txt", "rt");
  for (;res = fgets((char*)&buf, MAX_ITEMS, fp), res!=NULL;)
  {
    //count elements in rucksack
    for (buf_count=0; buf[buf_count] != '\n'; )
      buf_count++;

    //init 'hash' values to zero
    for (i=0; i<MAX_HASH_ELEMENTS; i++)
      fake_hash[i] = 0;

    //find repeating elements
    for (i=0; i<buf_count/2; i++)
      for (j=buf_count/2; j<buf_count; j++)
        if (buf[i] == buf[j])
          fake_hash[buf[i]] = 1;

    //calculate score for repeating elements
    for (i='A'; i<'z'+1; i++)
    {
      score = 0;
      if (1 == fake_hash[i])
      {
        if (i>='a' && i<='z')
          score = i-'a'+1;
        else
          score = i-'A'+('z'-'a'+1)+1;
      }
      total_score += score;
    }
  }

  fclose(fp);

  printf("total: %d\n", total_score);
  return 0;
}