#include <stdio.h>
#include <stdlib.h>

#define N 20

typedef struct{
  int id;
  char name[20];
  double gpa;
}Record;

int InputData(Record *);
void PrintData1(Record);
void PrintData2(Record *);

int main(){

  int i,j,status;

  Record data[N];

  for(i=0; ; i++){
    status=InputData(&data[i]);

    if(status==-1) break;
  }
  
  printf("値渡し\n");
  for(j=0;j<i;j++){
   
    PrintData1(data[j]);
  }
  
  printf("アドレス渡し\n");
  for(j=0;j<i;j++){
    
    PrintData2(&data[j]);
  }

  return 0;
}

int InputData(Record *s){
  scanf("%d", &s->id);
  scanf("%s",s->name);
  return scanf("%lf",&s->gpa);
}

void PrintData1(Record r){
  printf("%d            %s %.2f\n", r.id, r.name, r.gpa);
}

void PrintData2(Record *r){
  printf("%d            %s %.2f\n", r->id, r->name, r->gpa);
}
