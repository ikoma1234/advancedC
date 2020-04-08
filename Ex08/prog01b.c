#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int id;
  char name[20];
  double gpa;
}Record;

void PrintData1(Record);
void PrintData2(Record *);

int main(){

  Record data[2]={
    {12345,"Kondoh",3.21},{12346,"Okita",2.66}
  };
  
  printf("値渡し\n");
  PrintData1(data[0]);
  PrintData1(data[1]);
 
  printf("アドレス渡し\n");
  PrintData2(&data[0]);
  PrintData2(&data[1]);

  return 0;

}

void PrintData1(Record r){
  printf("%d            %s %.2f\n", r.id, r.name, r.gpa);
}

void PrintData2(Record *r){
  printf("%d            %s %.2f\n", r->id, r->name, r->gpa);
}
