#include <unistd.h>

void puts_fd(const char *s, int fd) {
  if(s == NULL) {
    write(fd, "(null)", 6);
    return;
  }
  while(*s) {
    write(fd, s, 1);
    s++;
  }
}
