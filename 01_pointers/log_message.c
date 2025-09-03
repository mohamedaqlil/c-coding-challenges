#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

void ft_putstr(char *s) {
  while(*s) {
    write(1, s, 1);
    s++;
  }
}

void ft_putnbr(signed int n) {
  if(n == -2147483648) {
    write(1, "-2147483648",11);
	return;
  }
  if(n < 0) {
	n = -n;
    write(1, "-", 1);
    ft_putnbr(n);
  }
  else if(n <= 9) {
    char c = n + '0';
    write(1, &c,1);
  }
  else {
    ft_putnbr(n / 10);
    ft_putnbr(n % 10);
  }
}

void log_message(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int i = 0;
  while(fmt[i]) {
    if(fmt[i] == '%') {
      if(fmt[i+1] == 's') {
        char *s = va_arg(args, char *);
        if(s == NULL) {
          ft_putstr("(null)");
        }
        else {
          ft_putstr(s);
        }
		i++;
      }
      if(fmt[i+1] == 'd') {
        signed int n = va_arg(args, signed int);
        ft_putnbr(n);
		i++;
      }
    }
    else {
      write(1, &fmt[i], 1);
    }
    i++;
  }
  va_end(args);
}
