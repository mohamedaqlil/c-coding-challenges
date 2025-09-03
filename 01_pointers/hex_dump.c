#include <stddef.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void hex_dump(const void *data, size_t size) {
  size_t i = 0;
  while(i < size) {
	printf("%02X", ((unsigned char*)data)[i]);
    printf(" ");
    i++;
  }
  printf("  ");
  size_t j = 0;
  while(j < size) {
    if(isprint(((unsigned char*)data)[j]) == 0) {
      printf(".");
    }
    else {
      printf("%c", ((unsigned char*)data)[j]);
    }
	j++;
  }
  printf("\n");
}

char *build_hex_dump(const void *data, size_t size) {
  char *result = malloc(size * 4 + 4);
  if(size == 0) {
    result[0] = '\0';
    return result;
  }
  int offset = 0;
  for (size_t line_start = 0; line_start < size; line_start += 16) {
    size_t bytes_in_line = (size - line_start > 16) ? 16 : (size - line_start);
    size_t i = 0;
    while(i < bytes_in_line) {
      offset += sprintf(result + offset, "%02X ", ((unsigned char*)data)[line_start + i]);
      i++;
    }
    offset += sprintf(result + offset, " ", ((unsigned char*)data)[line_start + i]);
    size_t j = 0;
    while(j < bytes_in_line) {
      if(isprint(((unsigned char*)data)[line_start + j]) == 0) {
        offset += sprintf(result + offset, ".", ((unsigned char*)data)[line_start + j]);
      }
      else {
        offset += sprintf(result + offset, "%c", ((unsigned char*)data)[line_start + j]);
      }
      j++;
    }
    offset += sprintf(result + offset, "\n", ((unsigned char*)data)[line_start + j]);
  }
  return result;
}
