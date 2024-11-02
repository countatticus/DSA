//Program 1.1: Menu-driven Stack

#include<stdio.h>
#include<stdlib.h>
#define size 5

void push(int item, int stack[], int *top){
    if (*top == size - 1){
        printf("Stack Overflow\n");
        return;
    }
    (*top)++;
    stack[*top] = item;
    printf("Item pushed: %d", item);
}

void pop(int stack[], int *top){
    if (*top == -1){
        printf("Stack Underflow\n");
        return;
    }
    int retval = stack[*top];
    (*top)--;
    printf("Item popped: %d\n", retval);
}

void display(int stack[], int top){
    if (top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("Contents of the stack: \n");
    for(int i = 0; i <= top; i++){
        printf("%d \n", stack[i]);
    }
}

int main(){
    int choice, item, stack[size];
    int top = -1;
    
    while(1){
        printf("\n Menu \n");
        printf("1. Push \n2. Pop \n3. Display \n4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter the item to push into the stack: ");
                scanf("%d", &item);
                push(item, stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option! Please enter a valid one. \n");
        }
    }
}