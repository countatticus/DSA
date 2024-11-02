//Program 1.5: Evaluate postfix expression

#include<stdio.h>
#include<math.h>
#include<string.h>
#define size 70

void push(int item, int stack[], int *top){
    if (*top == size - 1){
        printf("Stack overflow \n");
        return;
    }
    (*top)++;
    stack[*top] = item;
}

int pop(int stack[], int *top){
    if (*top == -1){
        printf("Stack underflow \n");
        return -1;
    }
    int retval = stack[*top];
    (*top)--;
    return retval;
}

int evaluate(char postfix[]){
    int i, n, op1, op2, res, top, stack[size];
    char symbol;
    top = -1;
    n = strlen(postfix);
    
    for (i = 0; i < n; i++){
        symbol = postfix[i];
        
        switch(symbol){
            case '+':
                op2 = pop(stack, &top);
                op1 = pop(stack, &top);
                res = op1 + op2;
                push(res, stack, &top);
                break;
            case '-':
                op2 = pop(stack, &top);
                op1 = pop(stack, &top);
                res = op1 - op2;
                push(res, stack, &top);
                break;
            case '*':
                op2 = pop(stack, &top);
                op1 = pop(stack, &top);
                res = op1 * op2;
                push(res, stack, &top);
                break;
            case '/':
                op2 = pop(stack, &top);
                op1 = pop(stack, &top);
                if (op2 != 0){
                    res = op1/op2;
                    push(res, stack, &top);
                } else {
                    printf("Error: Division by 0! \n");
                    return -1;
                }
                break;
            case '^':
            case '$':
                op2 = (double) pop(&top, stack);
                op1 = (double) pop(&top, stack);
                res = (int)pow(op1, op2);
                push(res, stack, &top);
                break;
            default:
                push(symbol - '0', stack, &top);
                break;
        }
    }
    return pop(stack, &top);
}

int main(){
    int result;
    char postfix[size];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    result = evaluate(postfix);
    printf("Result: %d\n", result);
}
