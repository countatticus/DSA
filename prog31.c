/*
NOTES

Edge cases
1. Empty linked list: (if first == NULL)
2. Single node: (if first -> next == NULL)

Stack and Queue implementation
Stack: insert_front() & del_front() OR insert_rear() & del_rear() + display()
Queue: insert_front() & del_rear() OR insert_rear() & del_front() + display()

Why sizeof(struct node)?
NODE is a pointer alias for struct node. Hence, size of pointer is returned instead of size of structure 'node'. 
*/

// STACK IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node *NODE;

//insert_front()
NODE insert_front(int item, NODE first){
    
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp -> info = item;
    temp -> next = first;
    return temp;
    
}

//del_front()
NODE del_front(NODE first){
    
    NODE temp;
    if (first == NULL){
        printf("Linked List is Empty. \n");
        return first;
    }
    temp = first;
    first = first -> next;
    printf("Item deleted: %d \n", temp -> info);
    free(temp);
    return(first);
    
}

//insert_rear()
NODE insert_rear(int item, NODE first){
    
    NODE temp, cur;
    
    //Initialize an (isolated) node first
    temp = (NODE)malloc(sizeof(struct node));
    temp -> info = item;
    temp -> next = NULL;
    
    if (first == NULL){
        return temp;
    }
    cur = first;
    while (cur -> next != NULL){
        cur = cur -> next;
    }
    cur -> next = temp;
    return first;
    
}

//del_rear()
NODE del_rear(NODE first){
    
    NODE prev, cur;
    if (first == NULL){
        printf("Linked List is Empty. \n");
        return first;
    }
    if (first -> next == NULL){
        printf("Item deleted: %d \n", first -> info);
        free(first);
        return(NULL);
    }
    prev = NULL;
    cur = first;
    while (cur -> next != NULL){
        prev = cur;
        cur = cur -> next;
    }
    printf("Item deleted: %d \n", cur -> info);
    free(cur);
    prev -> next = NULL;
    return(first);
    
}

//display()
void display(NODE first){
    
    NODE cur;
    if (first == NULL){
        printf("Linked List is Empty");
    }
    cur = first;
    printf("\nContents of Linked List \n");
    while (cur != NULL){
        printf("%d\n", cur -> info);
        cur = cur -> next;
    }
    
}

int main()
{
    int choice, item;
    
    NODE first = NULL;
    
    while(1){
        printf("\nMenu \n");
        printf("1. Push \n2. Pop \n3. Display \n4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &item);
                first = insert_front(item, first);
                break;
            case 2:
                first = del_front(first);
                break;
            case 3:
                display(first);
                break;
            case 4:
                exit(0);
            default: printf("Invalid choice. Please enter a new one. \n");
        }
    }

    return 0;
}