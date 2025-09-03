#include <unistd.h>
#include <limits.h>

void putnbr_fd(int n, int fd) {
  if(n == -2147483648) {
    write(fd, "-2147483648",11);
	return;
  }
  if(n < 0) {
	n = -n;
    write(fd, "-", 1);
    putnbr_fd(n, fd);
  }
  else if(n <= 9) {
    char c = n + '0';
    write(fd, &c, 1);
  }
  else {
    putnbr_fd(n / 10, fd);
    putnbr_fd(n % 10, fd);
  }
}
