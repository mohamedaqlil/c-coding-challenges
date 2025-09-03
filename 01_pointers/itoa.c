#include <stdlib.h>
#include <limits.h>

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
	return arr;
  }
  while (temp > 0) {
    arr[i-1] = temp%10 + '0';
	temp /= 10;
    i--;
  }
  return arr;
}
