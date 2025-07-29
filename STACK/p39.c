#include<stdio.h>
#include<stdlib.h>

struct interval{
    int in;
    int out;
};

struct interval stack[50];
int top=-1;

void push(struct interval x){
    if(top < (int)(sizeof(stack)/sizeof(int)-1)) {
        stack[++top]=x;
    }
    else {
        printf("Stack is full!!");
    }
}

struct interval pop(){
    if(top<0) {
        printf("Underflow!!!");
    }
    else {
        return stack[top--];
    }
}

void main() {
    printf("Enter No.of Intervals : ");
    int n;
    scanf("%d",&n);

    struct interval intervals[n];

    for(int i=0;i<n;i++) {
        printf("Enter in time of interval %d : ",(i+1));
        scanf("%d",&intervals[i].in);
        printf("Enter out time of interval %d : ",(i+1));
        scanf("%d",&intervals[i].out);
        printf("\n");
    }

    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(intervals[i].in>intervals[j].in) {
                struct interval temp=intervals[i];
                intervals[i]=intervals[j];
                intervals[j]=temp;
            }
        }
    }

    push(intervals[0]);
    for(int i=1;i<n;i++) {
        if(stack[top].out<intervals[i].in) {
            push(intervals[i]);
        }
        else{
           struct interval temp = pop();
           temp.out=(temp.out<intervals[i].out) ? intervals[i].out : temp.out;
           push(temp);
        }
    }
    printf("(");
    for(int i=0;i<=top;i++) {
        if(i!=top){
            printf("{%d,%d},",stack[i].in,stack[i].out);
        }
        else {
            printf("{%d,%d}",stack[i].in,stack[i].out);
        }
        
    }
    printf(")");
}