#include<stdio.h>
#include<string.h>
int main(){
        int s,i,j;
        printf("How many name you has been enter :");
        scanf("%d",&s);
        
        char a[s][25];
        char temp[25];
       
      

        printf("******Scaning of Array :****\n");
        for(i=0;i<s;i++){
                printf("Enter Element for index %d :",i);
                scanf("%s",&a[i]);
        
        }
        for (i = 0; i < s-1; i++) {
        for (j = i + 1; j < s; j++) {
            if (strcmp(a[i], a[j]) > 0) {
                strcpy(temp, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], temp);
            }
        }
    }
    printf("Sorted names:\n");
    for (i = 0; i < s; i++) {
        printf("%s\n", a[i]);
    }


        return 0;
}