#include <stdarg.h>

int sum_numbers(int count, ...) {
  if(count <= 0) {
    return 0;
  }
  va_list args;
  va_start(args, count);
  int sum = 0;
  for(int i = 0; i < count; i++) {
    int n = va_arg(args, int);
    sum += n;
  }
  va_end (args);
  return sum;
}
