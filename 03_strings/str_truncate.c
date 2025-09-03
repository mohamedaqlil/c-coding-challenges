#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *str_truncate(const char *s, size_t precision) {
  if(s != NULL) {
    size_t len = strlen(s);
    if(precision > len) {
      char *copy = malloc(len+1);
      memcpy(copy, s, len);
      copy[len] = '\0';
      return copy;
    }
    if(precision == 0) {
      char *copy = malloc(1);
      copy[0] = '\0';
      return copy;
    }
    char *copy = malloc(precision+1);
    memcpy(copy, s, precision);
    copy[precision] = '\0';
    return copy;
  }
  return NULL;
}
