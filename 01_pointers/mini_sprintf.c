#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *itoa(int n) {
  unsigned long nb = n;
  unsigned long temp = nb;
  if(n < 0) {
    temp = -nb;
  }
  else {
    temp = nb;
  }
  unsigned long copy = temp;
  unsigned long i = 0;
  while(copy != 0){
    copy /= 10;
    i++;
  }
  if(n <= 0) {
	i += 1;
  }
  char *arr = malloc(i+1);
  arr[i] = '\0';
  if(n < 0) {
    arr[0] = '-';
  }
  if(n == 0) {
	arr[0] = '0';
    arr[1] = '\0';
	return arr;
  }
  while (temp > 0) {
    arr[i-1] = temp%10 + '0';
	temp /= 10;
    i--;
  }
  return arr;
}

int mini_sprintf(char *buf, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int i = 0;
  int j = 0;
  while(fmt[j]) {
    if(fmt[j] == '%') {
      if(fmt[j+1] == 'd') {
        int n = va_arg(args, int);
        char *s = itoa(n);
        size_t len = strlen(s);
        memcpy(buf, s, len);
		buf += len;
        i += (int)len;
        free(s);
		j += 2;
        continue;
      }
      if(fmt[j+1] == 's') {
        char *s = va_arg(args, char *);
        int len = strlen(s);
        strcpy(buf, s);
		buf += len;
        i += len;
		j += 2;
        continue;
      }
      if(fmt[j+1] == 'c') {
		int temp = va_arg(args, int);
        char c = (char) temp;
        *buf = c;
        buf++;
        i++;
		j += 2;
        continue;
      }
      if(fmt[j+1] == '%') {
        *buf = '%';
        buf++;
        i++;
		j += 2;
        continue;
      }
    }
    else {
      *buf = fmt[j];
      j++;
      i++;
      buf++;
	}
  }
  *buf = '\0';
  va_end(args);
  return i;
}
