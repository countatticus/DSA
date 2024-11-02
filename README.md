# DSA notes
## Program 1.1: Menu-driven non-dynamic stack
**Push function** <br>
Parameters: ```item, stack[], *top```
```C
void push(int item, int stack[], int *top){
    if (*top == size - 1){
        printf("Stack Overflow\n");
        return;
    }
    (*top)++;
    stack[*top] = item;
    printf("Item pushed: %d", item);
}

```
**Pop function** <br>
Parameters: ```stack[], *top```
```C
void pop(int stack[], int *top){
    if (*top == -1){
        printf("Stack Underflow\n");
        return;
    }
    int retval = stack[*top];
    (*top)--;
    printf("Item popped: %d\n", retval);
}
```
## Program 1.2: Dynamic Stack
**Push function** <br>
Parameters: ```item, **stack, *top```
```C
void push(int item, int **stack, int *top){
    if (*top == size - 1){
        size = size * 2;
        *stack = (int *)realloc(*stack, size*sizeof(int));
        
        if (*stack == NULL){
            printf("Memory reallocation failed! \n");
            exit(1);
        }
        printf("Stack resized to %d \n", size);
    }
    (*top)++;
    (*stack)[*top] = item;
    printf("Item pushed: %d", item);
}
```
**Pop function** <br>
Parameters: ```*stack, *top```
```C
void pop(int *stack, int *top){
    if (*top == -1){
        printf("Stack Underflow\n");
        return;
    }
    int retval = stack[*top];
    (*top)--;
    printf("Item popped: %d\n", retval);
}
```
