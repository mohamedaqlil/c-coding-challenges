#include <stdarg.h>
#include <limits.h>

int max_of(int count, ...) {
  if(count <= 0) {
    return INT_MIN;
  }
  va_list args;
  va_start(args, count);
  int i = 0;
  int max = INT_MIN;
  while(i < count) {
    int n = va_arg(args, int);
    if(n > max) {
      max = n;
    }
    i++;
  }
  va_end (args);
  return max;
}
