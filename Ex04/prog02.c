#include <stdio.h>
int main()
{
  int x=3, y=7; /* この行は変更しない */
  int *p,*q;

  p=&x,q=&y;

  /* 以下の printf() の中を x,y を使わない形に書き換える */
  printf(" Value x: %d  (%p)\n", *p ,p );
  printf(" Value y: %d  (%p)\n", *q, q );
  printf(" Sum:     %d\n", *p+*q );
  printf(" Product: %d\n", *p**q);
  return 0;
}
