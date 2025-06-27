#include <stdio.h>
void main()
{
    int n,rim,ans=0;
    printf("Enter  number = ");
    scanf("%d",&n);
    while(n!=0)
    {
        rim=n%10;
       
        ans=(ans*10)+rim;
        n=n/10;
    }
    printf("%d",ans);
}