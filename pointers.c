// Pointer notes

#include<stdio.h>

int main(){
    
    int a = 5, *ptr;
    
    ptr = &a; //referencing a pointer to the address of a variable
    
    int y = *ptr; //dereferencing a pointer: y now holds the value stored in variable 'a'
    
    printf("Value of a = %d \n", a);
    printf("Address of a = %p \n", (void *)ptr); // 0x7ffd3ea0f8c8
    printf("y = %d \n", y);
    
    return 0;
}