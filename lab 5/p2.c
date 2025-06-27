#include<stdio.h>
int main()
{
         int j,k,l,i;
         
         int a[3][2],b[2][3],mul[3][3];
         printf("Scaning of First MAtrix is 3 by 2 :\n");
         for(i=0;i<3;i++)
         {
                for(j=0;j<2;j++)
                {
                        printf("Enter Element of %d row and %d col :",i+1,j+1);
                        scanf("%d",&a[i][j]);
                }
         }
         printf("Scaning of First MAtrix IS complated:\n");
         printf("Scaning of second MAtrix is 2 by 3:\n");
         for(i=0;i<2;i++)
         {
                for(j=0;j<3;j++)
                {
                        printf("Enter Element of %d row and %d col :",i+1,j+1);
                        scanf("%d",&b[i][j]);
                }
         }
         printf("Scaning of Second MAtrix IS complated:\n");

          for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
                mul[i][j]=0;
            for(k = 0; k < 2; k++) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

        printf("Printing of Metrix ******\n");

         for(k=0;k<3;k++)
           {
                for(l=0;l<3;l++)
                {
                        printf("%d   ",mul[k][l]);
                }
                printf("\n");
           } 
         
        return 0;
}