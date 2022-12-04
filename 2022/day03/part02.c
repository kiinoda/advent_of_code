#include <stdio.h>

#define MAX_ITEMS 127
#define MAX_HASH_ELEMENTS 128
#define GROUP_SIZE 3

int main()
{
  // this contains a bitmask of the presence of element in group
  int fake_hash[MAX_HASH_ELEMENTS];
  
  char buf[MAX_ITEMS];
  int i, pos, group_position, score, total_score;
  char *res;

  group_position = 0;
  total_score = 0;

  FILE *fp = fopen("input.txt", "rt");
  for (;res = fgets((char*)&buf, MAX_ITEMS, fp), res!=NULL;)
  {
    //reset all fake hash components to zero
    if (0==group_position)
      for (i='A'; i<'z'+1; i++)
        fake_hash[i] = 0;

    //set presence bits for elements per group_position
    for (pos=0; buf[pos] != '\n'; pos++)
      if (0 == (fake_hash[buf[pos]]>>group_position))
        fake_hash[buf[pos]] += (1<<group_position);

    //find component that is present in all 3 rucksack of the group
    if (2==group_position)
    {
      score = 0;
      for (i='A'; i<'z'+1; i++)
        if (7 == fake_hash[i])
        {
          if (i>='a' && i<='z')
            score = i-'a'+1;
          else
            score = i-'A'+('z'-'a'+1)+1;
        }
      total_score += score;
      group_position = 0;
    }
    else
      group_position++;
  }

  fclose(fp);

  printf("total: %d\n", total_score);
  return 0;
}