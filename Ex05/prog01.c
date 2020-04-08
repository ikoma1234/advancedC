#include <stdio.h>
int main()
{
   int i;
   int array[] = {11,22,33,44}; //アドレスは４ずつ増える
   long l_array[] = {123,234,345,456};//アドレスは８ずつ増える
   char c_array[] = {'a','b','c','d'};//アドレスは１ずつ増える
   char *str_array[] = {"A","BC","DEF","GHIJK"};//アドレスは８ずつ増える
   double d_array[] = {1e-3, 2e-4, 3e-5, 4e-6};//アドレスは８ずつ増える
   char array_2dc[][10] = {"a","bcde","fgh","ij"};//アドレスは１０ずつ増える


   for(i = 0 ; i < 4 ; i++){
     printf( "%d %p %d\n",i,&array[i],array[i]);
     printf( "%d %p %ld\n",i,&l_array[i],l_array[i]);
     printf( "%d %p %d\n",i,&c_array[i],c_array[i]);
     printf( "%d %p %s\n",i,&str_array[i],str_array[i]);
     printf( "%d %p %f\n",i,&d_array[i],d_array[i]);
     printf( "%d %p %s\n",i,array_2dc[i],array_2dc[i]);
   }
     
   printf("\n%p\n",array);
   printf("\n%p\n",l_array);
   printf("\n%p\n",c_array);
   printf("\n%p\n",str_array);
   printf("\n%p\n",d_array);
   printf("\n%p\n",array_2dc);

   return 0;
}
