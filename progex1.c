#include<stdio.h>
#include<stdlib.h>
#define size 10

void push_stack1(int item, int stack[], int *top1, int *top2){
    if (*top1 == *top2 - 1){
        printf("[Stack 1] Stack overflow \n");
        return;
    }
    (*top1)++;
    stack[*top1] = item;
    printf("Item pushed: %d \n", item);
}

void push_stack2(int item, int stack[], int *top1, int *top2){
    if (*top1 == *top2 - 1){
        printf("[Stack 2] Stack overflow \n");
        return;
    }
    (*top2)--;
    stack[*top2] = item;
    printf("Item pushed: %d \n", item);
}

void pop_stack1(int stack[], int *top1){
    if (*top1 == -1){
        printf("[Stack 1] Stack underflow \n");
        return;
    }
    int retval = stack[*top1];
    (*top1)--;
    printf("Item popped: %d \n", retval);
}

void pop_stack2(int stack[], int *top2){
    if (*top2 == size){
        printf("[Stack 2] Stack underflow \n");
        return;
    }
    int retval = stack[*top2];
    (*top2)++;
    printf("Item popped: %d \n", retval);
}

void display_stack1(int stack[], int top1){
    if (top1 == -1){
        printf("[Stack 1] Stack is empty \n");
        return;
    }
    for (int i = 0; i <= top1; i++){
        printf("%d \n", stack[i]);
    }
}

void display_stack2(int stack[], int top2){
    if (top2 == size){
        printf("[Stack 2] Stack is empty \n");
        return;
    }
    for (int i = size; i >= top2; i--){
        printf("%d \n", stack[i]);
    }
}

int main(){
    int choice, item, stack_num, stack[size];
    int top1 = -1, top2 = size;
    
    while(1){
        printf("\n Menu \n");
        printf("1. Push \n2. Pop \n3. Display \n4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter stack number: ");
                scanf("%d", &stack_num);
                printf("Enter item to push: ");
                scanf("%d", &item);
                if (stack_num == 1){
                    push_stack1(item, stack, &top1, &top2);
                } else {
                    push_stack2(item, stack, &top1, &top2);
                }
                break;
            case 2:
                printf("Enter stack number: ");
                scanf("%d", &stack_num);
                if (stack_num == 1){
                    pop_stack1(stack, &top1);
                } else {
                    pop_stack2(stack, &top2);
                }
                break;
            case 3:
                printf("Enter stack number: ");
                scanf("%d", &stack_num);
                if (stack_num == 1){
                    display_stack1(stack, top1);
                } else {
                    display_stack2(stack, top2);
                }
                break;
            case 4:
                exit(0);
            default: printf("Invalid choice! Please enter a valid one. \n");
        }
    }
    return 0;
}
