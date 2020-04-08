#include <stdio.h>
#include <stdlib.h>
#include "prog01.h"

#define N 20

Record input (void);
void output(Record);
int getage(Record);

int main(){
  
  Record data[20];  /* これはmain関数の中に書く              */
  int i=0;
  
  printf("--------データ出力--------\n");
  printf("年齢基準日：2018年10月1日\n");

  while(1){

    data[i]=input();
    if(data[i].gender==-1) break;
    
    printf("%2d人目:",i+1);
    output(data[i]);

    i++;
  }

  return 0;
}

Record input(void){

  Record data;

  if(scanf("%s", data.surname)==EOF) data.gender=-1;
  scanf("%d", &data.birthday[0]);
  scanf("%d", &data.birthday[1]);
  scanf("%d", &data.birthday[2]);
  scanf("%d", &data.gender);

  return data;
}

void output(Record data){
  
  printf("名前(姓): %-13s", data.surname);
  printf("%4d年%2d月%2d日生 年齢：%2d ", data.birthday[0], data.birthday[1], data.birthday[2], getage(data));

  if(data.gender==0){
    printf("男性\n");
  }
  else if(data.gender==1){
    printf("女性\n");
  }
}

int getage(Record data){
  
  int year = 2018;
  int month = 10;
  int day = 1;

  int y = year - data.birthday[0];
  if (month < data.birthday[1])
    y--;
  else if (month == data.birthday[1] && day < data.birthday[2])
    y--;

  return y;
}

  
