#include<stdio.h>
#include<stdlib.h>

int main(){
        int a=3;
        float b=4;
        char c='a';

       int* ptra=(int*)malloc(sizeof(int));
       float* ptrb=(float*)malloc(sizeof(float));
       char* ptrc=(char*)malloc(sizeof(char));

       if(ptra && ptrb && ptrc)
       {
         printf("Memory allocation is Succesfull Now We doing further Process \n");

        ptra=&a;
         ptrb=&b;
          ptrc=&c;

          printf("Intiger is :%d\n",*ptra);
          printf("Float is :%f\n",*ptrb);
          printf("Char is :%c\n",*ptrc);

            free(ptra);
            free(ptrb);
            free(ptrc);

       }
       else{
        printf("Memory allocation is failed \n");
       }
       return 0;
}