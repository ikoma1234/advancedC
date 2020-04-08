#include <stdio.h>
#include <stdlib.h>
#include "prog01.h"

Record input (void);
void output(Record);
int getage(Record);

int main(){
  
  Record data[2];  /* これはmain関数の中に書く              */

  printf("--------データ入力--------\n");
  printf("1人目の");
  data[0]=input();
  printf("2人目の");
  data[1]=input();

  printf("--------データ出力--------\n");
  printf("年齢基準日：2018年10月1日\n");
  printf("1人目のデータ\n");
  output(data[0]);
  printf("年齢：");
  printf("%d",getage(data[0]));
  printf("\n");
  getage(data[0]);
  printf("2人目のデータ\n");
  output(data[1]);
  printf("年齢：");
  printf("%d",getage(data[1]));
  printf("\n");

  return 0;
}

Record input(void){

  Record data;
  
  printf("データを入力して下さい");
  printf("名前（姓）        ->");
  scanf("%s", data.surname);
  printf("生まれた年（西暦） ->");
  scanf("%d", &data.birthday[0]);
  printf("生まれた月        ->");
  scanf("%d", &data.birthday[1]);
  printf("生まれた日        ->");
  scanf("%d", &data.birthday[2]);
  printf("性別(0:男性,1:女性) ->");
  scanf("%d", &data.gender);

  return data;
}

void output(Record data){
  
  printf("\n名前(姓): %s", data.surname);
  printf("\n生年月日: %d年 %d月 %d日", data.birthday[0], data.birthday[1], data.birthday[2]);

  if(data.gender==0){
    printf("(男性)\n");
  }
  else if(data.gender==1){
    printf("(女性)\n");
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

  
