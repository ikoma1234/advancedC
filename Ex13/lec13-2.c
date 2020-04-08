#include <stdio.h>

#define TATE 3
#define YOKO 4

struct arr {
  int a[TATE][YOKO];
};

void print_ar1(int (*p)[YOKO]);
void print_ar2(int x[TATE][YOKO]);
void print_ar3(struct arr);

int main()
{
  int i, j, a[TATE][YOKO] = {{1,2,3,4},
			     {2,3,4,5},
			     {3,4,5,6}};
  struct arr b;

  for(i = 0; i < TATE; i++)
    for(j = 0; j < YOKO; j++) 
      b.a[i][j] = a[i][j];

  print_ar1(a);
  printf("-------------\n");
  print_ar2(a);
  printf("-------------\n");
  print_ar3(b);

  return 0;
}

void print_ar1(int (*p)[YOKO])
{
  int i,j;

  printf("size : %d\n",sizeof(p));
  for(i = 0; i < TATE; i++){
    for(j = 0; j < YOKO; j++) 
      printf("%2d ",p[i][j]);
    printf("\n");
  }
}


void print_ar2(int x[TATE][YOKO])
{
  int i,j;

  printf("size : %d\n",sizeof(x));
  for(i = 0; i < TATE; i++){
    for(j = 0; j < YOKO; j++) 
      printf("%2d ",x[i][j]);
    printf("\n");
  }
}

void print_ar3(struct arr y)
{
  int i,j;

  printf("size : %d\n",sizeof(y.a));
  for(i = 0; i < TATE; i++){
    for(j = 0; j < YOKO; j++) 
      printf("%2d ",y.a[i][j]);
    printf("\n");
  }
}


