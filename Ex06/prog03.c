#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

  int i=1, elem;
  char *out;

  while(1){

    elem=atoi(argv[i]);
    out=malloc(elem*sizeof(char));
	       
    printf("%s　->\n", argv[i]);
    i++;

    if(argv[i]==NULL) break;

  }

  return 0;
}
