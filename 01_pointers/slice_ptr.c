#include <stddef.h>

const int* slice_ptr(const int *arr, int len, int start, int count) {
  if (start >= 0 && count >= 0 && start < len && start + count <= len) {
    int i = 0;
    while(i < start) {
      arr++;
      i++;
    }
    return arr;
  }
  return NULL;
}

int sum_ptr(const int *start_ptr, int count) {
  if(count != 0) {
    int i = 0;
    int sum = 0;
    while(i < count) {
      i++;
      sum += *start_ptr;
      start_ptr++;
    }
    return sum;
  }
  return 0;
}

void reverse_range(int *start_ptr, int count) {
  if(count <= 1) {
    return;
  }
  int *start = start_ptr;
  int i = 1;
  while(i < count) {
    i++;
    start_ptr++;
  }
  int s = 1;
  int c = count/2;
  while(c--) {
    int temp = *start;
    *start = *start_ptr;
    *start_ptr = temp;
    start++;
    start_ptr--;
	s++;
  }
}
