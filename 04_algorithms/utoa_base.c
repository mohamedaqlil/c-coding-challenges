#include <stdlib.h>

int ft_strlen(char *s) {
  int i = 0;
  while(*s) {
    i++;
    s++;
  }
  return i;
}

void swap(char *s1, char *s2) {
  char tmp = *s1;
  *s1 = *s2;
  *s2 = tmp;
}

void restring(char *s) {
  int i = 0;
  int end = ft_strlen(s) - 1;
  while(i < end) {
    swap(&s[i], &s[end]);
    i++;
    end--;
  }
}

char *utoa_base(unsigned int n, int base, int uppercase) {
  char *s = malloc(33);
  char hex[] = "0123456789abcdef";
  char HEX[] = "0123456789ABCDEF";
  char binary[] = "01";
  if(n == 0) {
    char *zs = malloc(2);
    zs[0] = '0';
    zs[1] = '\0';
    return zs;
  }
  if(base >= 2 && base <= 16) {
    if(uppercase == 0 && base == 16) {
      int i = 0;
      while(n != 0) {
        s[i] = hex[n%16];
        n /= 16;
        i++;
      }
      s[i++] = '\0';
      restring(s);
      return s;
    }
    if(uppercase == 1 && base == 16) {
      int i = 0;
      while(n != 0) {
        s[i] = HEX[n%16];
        n /= 16;
        i++;
      }
      s[i++] = '\0';
      restring(s);
      return s;
    }
    if(base == 2) {
      int i = 0;
      while(n != 0) {
        s[i] = binary[n%2];
        n /= 2;
        i++;
      }
      s[i++] = '\0';
      restring(s);
      return s;
    }
  }

  return NULL;
}
