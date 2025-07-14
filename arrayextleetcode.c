#include<stdio.h>

int main(){
    int i = 0 , index = 0 , product = 1 , flag =1;
    int arr = {1,2,3,4};
    int result[4];

    while (flag)
    {
        if (i < 4)
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
        if (index >= 4)
        {
            flag = 0;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        printf("%d" , result[i]);
    }
    
    
}