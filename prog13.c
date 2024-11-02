//Program 1.3: Multiple stacks (non-dynamic)

#include<stdio.h>
#include<stdlib.h>

#define size 100
int stack[size], top[10], boundary[10];

void push(int item, int i){
    if (top[i] == boundary[i + 1]){
        printf("Stack %d: Stack overflow \n", i);
        return;
    }
    top[i]++;
    stack[top[i]] = item;
    printf("[Stack %d] Item pushed: %d \n", i, item);
}

int pop(int i){
    if (top[i] == boundary[i]){
        printf("Stack %d: Stack underflow \n", i);
        return -1;
    }
    int retval = stack[top[i]];
    top[i]--;
    printf("[Stack %d] Item popped: %d \n", i, retval);
    
    return retval;
}

void display(int i){
    if (top[i] == boundary[i]){
        printf("Stack %d: Empty \n", i);
        return;
    }
    printf("Stack %d contents: \n", i);
    for (int j = boundary[i] + 1; j <= top[i]; j++){
        printf("%d \n", stack[j]);
    }
}

int main(){
    int choice, item, n, i;
    
    printf("Enter the number of stacks: ");
    scanf("%d", &n);
    
    //boundaries and tops for each stacks
    for (int i = 0; i <= n; i++){
        top[i] = boundary[i] = size / n*i-1;
    }
    
    while (1){
        printf("\n Menu \n");
        printf("1. Push \n2. Pop \n3. Display \n4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter the stack number: ");
                scanf("%d", &i);
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(item, i);
                break;
            case 2:
                printf("Enter the stack number: ");
                scanf("%d", &i);
                pop(i);
                break;
            case 3:
                printf("Enter the stack number: ");
                scanf("%d", &i);
                display(i);
                break;
            case 4:
                exit(0);
            default:
            printf("Invalid choice \n");
            break;
        }
    }
    return 0;
}