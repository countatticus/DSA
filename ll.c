// Linked List #1: Stack and Queue Implementation

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int info;
	struct node *next;
} *NODE;

NODE insert_front(int item, NODE first){
	
	NODE temp = (NODE)malloc(sizeof(struct node));
	temp -> info = item;
	temp -> next = first;
	return temp;

}

NODE del_front(NODE first){

	NODE temp;
	if (first == NULL){
		printf("List is empty. \n");
		return (first);
	}
	temp = first;
	first = first -> next;
	printf("Item Deleted: %d \n", temp -> info);
	free(temp);
	return (first);

}

NODE insert_rear(int item, NODE first){

	NODE temp, cur;
	
	//create a temporary node
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
 
