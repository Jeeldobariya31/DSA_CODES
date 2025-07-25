#include<stdio.h>

int main(){
    int size;
    printf("Enter Size : ");
    scanf("%d",&size);
    int i = 0 , index = 0 , product = 1 , flag =1;
    int arr[size] ;
    for(int j=0;j<size;j++){
        printf("Enter %d th element :",(j+1));
        scanf("%d",arr[i]);
    }
    int result[size];

    while (flag)
    {
        if (i < size)
        {
            if (i != index)
            {
                product = product * arr[i];
                i++;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i = 0;
            product = 1;
            result[index]= product;
            index++;
        }
        if (index >= size)
        {
            flag = 0;
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d" , result[i]);
    }
    
    
}