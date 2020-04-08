#include <stdio.h>

double seqavg(double);
int main(){

  int status;
  int i=0;
  double data, avg;

  while(1){
    printf("データを入力してください:");
    status=scanf("%lf",&data);
    if (status!=1){
      printf("\n最終的な平均値は%fです。\n",avg);
      break;
    }
    i++;

    avg=seqavg(data);
  
    printf("データの個数=%d,　ここまでの平均=%f \n", i, avg);
  }

  return 0;
}

double seqavg(double data){
  static double ave=0;
  static int i=1;
  ave=(ave*(i-1)+data)/i;

  i++;

  return ave;
}
  

  
