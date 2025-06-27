#include<stdio.h>
int main()
{
         int row,col,j,k,l,i;
         printf("Enter matrix row and col in given order :");
         printf("Enter Row :");
         scanf("%d",&row);
         printf("Enter Col :");
         scanf("%d",&col);
         int a[row][col],b[row][col],sum[row][col];
         printf("Scaning of First MAtrix :\n");
         for(i=0;i<row;i++)
         {
                for(j=0;j<col;j++)
                {
                        printf("Enter Element of %d row and %d col :",i+1,j+1);
                        scanf("%d",&a[i][j]);
                }
         }
         printf("Scaning of First MAtrix IS complated:\n");
         printf("Scaning of second MAtrix :\n");
         for(i=0;i<row;i++)
         {
                for(j=0;j<col;j++)
                {
                        printf("Enter Element of %d row and %d col :",i+1,j+1);
                        scanf("%d",&b[i][j]);
                }
         }
         printf("Scaning of Second MAtrix IS complated:\n");

           for(k=0;k<row;k++)
           {
                for(l=0;l<col;l++)
                {
                        sum[k][l]=a[k][l]+b[k][l];
                }
           } 
        printf("Printing of Metrix ******\n");

         for(k=0;k<row;k++)
           {
                for(l=0;l<col;l++)
                {
                        printf("%d   ",sum[k][l]);
                }
                printf("\n");
           } 
       
        return 0;
}