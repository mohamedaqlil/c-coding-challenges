#include <stdlib.h>

int *ft_rrange(int start, int end) {
  int size;
  if (start < end)
  {
    size = end - start + 1;
  }
  else
  {
    size = start - end + 1;
  }

  int *arr = malloc((long)size * sizeof(int));

  int i = 0;
  if (start < end)
  {
    while(i < size) {
      arr[i] = end;
      i++;
      end--;
    }
  }
  if (start > end)
  {
    while(i < size) {
      arr[i] = end;
      i++;
      end++;
    }
  }
  return arr;
}
