#include <stdio.h>
#include <stdlib.h>

char grade_char(int);

int main(int argc, char *argv[]){

  int i=1, num;
  
  while(1){

  num=atoi(argv[i]);
    
  printf("Point %d: %c\n", num, grade_char(num));
    
  i++;

  if(argv[i]==NULL) break;
  }

  
  return 0;
}
  
  char grade_char(int score){
    if(score<35)
      return 'F';
    else if(score<50)
      return 'D';
    else if(score<65)
      return 'C';
    else if(score<80)
      return 'B';
    else;
    return 'A';
  }
