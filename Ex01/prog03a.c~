#include <stdio.h>
#include <math.h>

char grade_char(int);
int char_point(char);

int main(void){

  int hyouten, tanisuu;
  int goukeitanisuu=0;
  double GPA=0;

  while(1){
  printf("評点と単位数を入力してください:");
  scanf("%d%d",&hyouten,&tanisuu);

  printf("%d点の評価は%cで、Grade Point(GP)は%dです。(%d　単位)\n", hyouten, grade_char(hyouten), char_point(grade_char(hyouten)), tanisuu);
  goukeitanisuu+=tanisuu;
  GPA+=(double)(char_point(grade_char(hyouten))*tanisuu);
  }

  GPA=GPA/goukeitanisuu;
  printf("Grade Point Average(GPA): %f, 単位数: %d",GPA,goukeitanisuu);

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

int char_point(char c){
  if(c=='A')
    return 4;
  if(c=='B')
    return 3;
  if(c=='C')
    return 2;
  else
    return 0;
}
  

  
