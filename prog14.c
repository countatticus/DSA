//Program 1.4: Infix to postfix

#include<stdio.h>
#include<string.h>
#define size 70

int input_precedence(char symbol){
    switch(symbol){
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' : 
        case '%' : return 3;
        case '^' : 
        case '$' : return 6;
        case '(' : return 9;
        case ')' : return 0;
        default  : return 7;
    }
}

int stack_precedence(char symbol){
    switch(symbol){
        case '+' :
        case '-' : return 2;
        case '*' :
        case '/' : 
        case '%' : return 4;
        case '^' : 
        case '$' : return 5;
        case '(' : return 0;
        case '#' : return -1;
        default  : return 8;
    }
}

void push(char item, char stack[], int *top){
    if (*top == size - 1){
        printf("Stack overflow \n");
        return;
    }
    (*top)++;
    stack[*top] = item;
}

char pop(char stack[], int *top){
    if (*top == -1){
        printf("Stack underflow \n");
        return -1;
    }
    char item = stack[*top];
    (*top)--;
    return item;
}

void infix_postfix(char infix[], char postfix[]){
    int j = 0, top = -1;
    char symbol, stack[size];
    push('#', stack, &top);
    int n = strlen(infix);
    
    for(int i = 0; i < n; i++){
        symbol = infix[i];
        
        while (stack_precedence(stack[top]) > input_precedence(symbol)){
            postfix[j] = pop(stack, &top);
            j++;
        }
        
        if (stack_precedence(stack[top]) != input_precedence(symbol)){
            push(symbol, stack, &top);
        } else {
            pop(stack, &top);
        }
    }
    
    while(stack[top] != '#'){
        postfix[j] = pop(stack, &top);
        j++;
    }
    postfix[j] = '\0';
}

int main(){
    char infix[size], postfix[size];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infix_postfix(infix, postfix);
    printf("The corresponding postfix expression is: %s", postfix);
    return 0;
}