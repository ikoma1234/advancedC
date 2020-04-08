#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
  char  sid[8];
  char  surname[10];
  int   score[4];
  char  grade;
  double ave;
} Record;

char grade_char(double);

int main(int argc, char *argv[]){

  Record data[20];
  int i=0,j,status;
  char sorn[20];
  FILE *fp;

  if((fp=fopen(argv[1],"r"))==NULL){
    printf("Error!  Usage: ./a.out datafilename\n");
    exit(1);
  }
  
  while(1){
    
    status=fscanf(fp, "%s%s%d%d%d%d", &data[i].sid,&data[i].surname,&data[i].score[0],&data[i].score[1],&data[i].score[2],&data[i].score[3],&data[i].grade);

    if(status==-1) break;

    data[i].ave=(double)((double)data[i].score[0]+(double)data[i].score[1]+(double)data[i].score[2]+(double)data[i].score[3])/4.0;

    data[i].grade=grade_char(data[i].ave);

    printf("%s %-10s %2d %2d %2d %2d",data[i].sid,data[i].surname,data[i].score[0],data[i].score[1],data[i].score[2],data[i].score[3]);
    printf(" %f %c \n",data[i].ave,data[i].grade);
    
    i++;
  }

  while(1){
    printf("Input a student name/ID :");
    status=scanf("%s",&sorn);

    if(status==-1){
      printf("\n");
      break;
    }
    
    if(sorn[0]>=49&&sorn[0]<=57){
      for(j=0;j<i;j++){
	if(strcmp(sorn,data[j].sid)==0){
	  printf("%s %-10s %2d %2d %2d %2d",data[j].sid,data[j].surname,data[j].score[0],data[j].score[1],data[j].score[2],data[j].score[3]);
	  printf(" %f %c \n",data[j].ave,data[j].grade);
	}
      }
    }
    else{
      for(j=0;j<i;j++){
	if(strcmp(sorn,data[j].surname)==0){
	  printf("%s %-10s %2d %2d %2d %2d",data[j].sid,data[j].surname,data[j].score[0],data[j].score[1],data[j].score[2],data[j].score[3]);
	  printf(" %f %c \n",data[j].ave,data[j].grade);
	}
      }
    }
  }
  
  return 0;
}

char grade_char(double score){
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
