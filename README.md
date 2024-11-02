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

### Differences

||Menu-driven|Dynamic|
|:---:|:---|:---|
|```size``` initialization|```#define size 5```|```int size = 5;```|
|```Push``` & ```Pop``` parameters|Push: ```item, stack[], *top``` <br> Pop: ```stack[], *top```|Push: ```item, **stack, *top``` <br> Pop: ```*stack, *top```|
|Overflow notice|```printf("Stack overflow \n):```|```size = size * 2;``` <br> ``` *stack = (int *)realloc(*stack, size*sizeof(int));```|
|```stack``` initialization|```int stack[size]```|```int* stack = (int *) malloc(size*sizeof(int))```|
|```push``` & ```pop``` function call|```push(item, stack, &top)``` <br> ```pop(stack, &top)```|```push(item, &stack, &top)``` <br> ```pop(stack, &top)```|
|case 4|```exit(0);```|```free(stack);``` <br> ```exit(0);```|

## Program 1.3: Multiple Stacks

**Push function** <br>
Parameters: ```item, i```

```C
void push(int item, int i){
    if (top[i] == boundary[i + 1]){
        printf("Stack %d: Stack overflow \n", i);
        return;
    }
    top[i]++;
    stack[top[i]] = item;
    printf("[Stack %d] Item pushed: %d \n", i, item);
}
```

**Pop function** <br>
Parameters: ```i``` <br>
Return type: ```int```

```C
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
```
