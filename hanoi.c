#include<stdio.h>
#include<conio.h>

int count = 0;

void tower(int n, char source, char destination, char temp){
    if (n == 1){
        printf("Mover %d disc from %c to %c \n", n, source, destination);
        count++;
        return;
    }
    tower(n - 1, source, temp, destination);
    printf("Move %d disc from %c to %c \n", n, source, destination);
    count++;
    tower(n - 1, temp, destination, source);
}

void main(){
    int n;
    printf("Enter the number of discs \n");
    scanf("%d", &n);
    tower(n, 'S', 'D', 'T');
    printf("The total number of disc moves = %d", count);
    getch();
}