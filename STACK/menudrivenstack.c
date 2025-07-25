//menu driven stack
#include<stdio.h>
#include<stdlib.h>

#define size 20

int top = -1;
int stack[size];

void push(int c) {
    if (top >= size - 1) {
        printf("Stack overflow ...\n");
    } else {
        stack[++top] = c;
    }
}

int pop() {
    if (top < 0) {
        printf("Stack underflow ...\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int peep() {
    if (top < 0) {
        printf("Stack underflow ...\n");
        return -1;
    } else {
        return stack[top];
    }
}

void change(int c, int pos) {
    if (top - pos + 1 < 0) {
        printf("Stack underflow ...\n");
        return;
    } else {
        stack[top - pos + 1] = c;
    }
}

void display() {
    if (top < 0) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack is : ");
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) printf(", ");
    }
    printf("\nPrinting completed .....\n");
}

int main() {
    int ch;
    do {
        printf("\n1. Push\n2. Pop\n3. Peep\n4. Change\n5. Display\n0. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                int ele;
                printf("Enter element to push: ");
                scanf("%d", &ele);
                push(ele);
                break;
            }
            case 2: {
                int ele = pop();
                if (ele != -1)
                    printf("Popped element is %d.\n", ele);
                break;
            }
            case 3: {
                int ele = peep();
                if (ele != -1)
                    printf("Top element is %d.\n", ele);
                break;
            }
            case 4: {
                int ele, pos;
                printf("Enter position to change: ");
                scanf("%d", &pos);
                printf("Enter new element: ");
                scanf("%d", &ele);
                change(ele, pos);
                break;
            }
            case 5:
                display();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice ......\n");
        }
    } while (ch != 0);
    
    return 0;
}
