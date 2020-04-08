#include <stdio.h>
#include <string.h>

int checkString(char *);

int main()
{
  int i;
  char newsstring[6][15]={"Good News", "Bad News", "Happy News", 
              "Sweet News", "Scary News", "Wonderful News"};

  for(i = 0; i < 6; i++) {
    /* If a string contains the patterns "Bad" or "Scary", 
       replace it with the new string "Cool News". */

    if(checkString(newsstring[i])==0){
      strcpy(newsstring[i],"Cool News");
    }

    
   /* ここを作成する */  


  }
  
  /* Print out the result */
  printf("--\n");
  for(i = 0; i < 6; i++) printf("%2d %s\n",i ,newsstring[i]);
  printf("--\n");
  
  return 0;
}

/* Check whether a string contains the patterns "Bad" or "Scary" 
   at the first n characters using strncmp function */
/* Refer to the command "man strcmp" for the strncmp function. */
int checkString(char *str)
  {

    char Bad_News[15]="Bad News";
    char Scary_News[15]="Scary News";
    
    if(strcmp(str, Bad_News)==0){
      return 0;
    }
    else if(strcmp(str, Scary_News)==0){
      return 0;
    }
    else{
      return 1;
    }
      
   /* ここを作成する */  

}
