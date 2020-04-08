#include <stdio.h>
#include <ctype.h> /* 関数toupperを使うため */

void printFavoriteVehicle(char *);

int main() {
  char *vehicles[]={"train", "car", "motorbike"};
  int i;

  printf("Suppose that we now have (0) %s, (1) %s, (2) %s.\n",
                                    vehicles[0],vehicles[1],vehicles[2]);
  printf("Which do you like?\n");
  printf("Input 0, 1, or 2: ");
  scanf("%d",&i);
  
  if(0 <= i && i <= 2) { /* i が 0-2 の範囲になければエラーを避けるため何もしない */
    printFavoriteVehicle(vehicles[i]);
  }  
  return 0;
}

void printFavoriteVehicle(char *favoritevehicle) {
  
  printf("%c",toupper(favoritevehicle[0])); /* 最初の文字を大文字で出力 */
  printf("%s", &favoritevehicle[1]); /* 二文字目以降を出力 */
  printf(" is your favorite vehicle!\n");
  
}
