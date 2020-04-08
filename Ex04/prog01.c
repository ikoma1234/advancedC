#include <stdio.h>

int main()
{
  int n = 123;
  int *p;

  p = &n;
  printf("(1) %d\n", n);
  printf("(2) %p\n", &n);
  printf("(3) %p\n", p);
  printf("(4) %d\n", *p);
  printf("(5) %p\n", &p);
  return 0;
}
