#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char usn[10];
	char name[20];
	char branch[5];
	int sem;
	char phoneno[10];
	
	struct node *right;
	struct node *left;
} *NODE;

//Insert Front
NODE insert_front(char usn[], char name[], char branch[], int sem, char phoneno[], NODE first){

	//create new node
	NODE temp = (NODE)malloc(sizeof(struct node));
	
	strcpy(temp -> usn, usn);
	strcpy(temp -> name, name);
	strcpy(temp -> branch, branch);
	strcpy(temp -> phoneno, phoneno);
	temp -> sem = sem;
	
	temp -> right = NULL;
	temp -> left = NULL;
	
	if (first == NULL){
		return temp;
	}
	temp -> right = first;
	first -> left = temp;
	return temp;
}

NODE insert_rear(char usn[], char name[], char branch[], int sem, char phoneno[], NODE first){

	//create new node
	NODE temp = (NODE)malloc(sizeof(struct node));

	strcpy(temp -> usn, usn);
	strcpy(temp -> name, name);
	strcpy(temp -> branch, branch);
	strcpy(temp -> phoneno, phoneno);
	temp -> sem = sem;

	temp -> left = NULL;
	temp -> right = NULL;
	
	if (first == NULL){
		return temp;
	}
	
	//traverse through the linked list to find the last node
	NODE cur = first;
	while (cur -> right != NULL){
		cur = cur -> right;
	}
	cur -> right = temp;
	temp -> left = cur;
	return first;
}

NODE del_front(NODE first){

	//no node exists
	if (first == NULL){
		printf("List is empty. \n");
		return first;
	}
	
	//only 1 node exists
	if (first -> right == NULL){
		printf("Student Details: \n");
		printf("USN: %s \nName: %s\n", first -> usn, first -> name);
		printf("Branch: %s \nSemester: %d\n", first -> branch, first -> sem);
		printf("Phone no.: +91%s\n", first -> phoneno);
		
		free(first);
		return(NULL);
	}
	
	//isolate the first node from the rest of the linked list before deleting
	NODE temp = first;
	temp -> right -> left = NULL;
	first = first -> right;
	
	printf("Student Details: \n");
	printf("USN: %s \nName: %s\n", temp -> usn, temp -> name);
	printf("Branch: %s \nSemester: %d\n", temp -> branch, temp -> sem);
	printf("Phone no.: +91%s\n", temp -> phoneno);
	
	free(temp);
	return first;
}

NODE del_rear(NODE first){

	NODE temp;
	
	//no node exists
	if (first == NULL){
		printf("List is empty. \n");
		return first;
	}
	
	//only 1 node exists
	if (first -> right == NULL){
		printf("Student Details: \n");
		printf("USN: %s \nName: %s\n", first -> usn, first -> name);
		printf("Branch: %s \nSemester: %d\n", first -> branch, first -> sem);
		printf("Phone no.: +91%s\n", first -> phoneno);
		
		free(first);
		return(NULL);
	}
	
	//traverse the linked list to find the last node
	temp = first;
	while (temp -> right != NULL){
		temp = temp -> right;
	}
	
	//isolate the last node from the previous one
	temp -> left -> right = NULL;
	
	printf("Student Details: \n");
	printf("USN: %s \nName: %s\n", temp -> usn, temp -> name);
	printf("Branch: %s \nSemester: %d\n", temp -> branch, temp -> sem);
	printf("Phone no.: +91%s\n", temp -> phoneno);
	
	free(temp);
	return first;
}

void display(NODE first){

	NODE temp;
	int count = 0;
	
	if (first == NULL){
		printf("Linked List is empty: %d Nodes\n", count);
		return;
	}
	
	temp = first;
	printf("Student Details: \n");
	printf("USN\tName\tBranch\tSemester\tPhone no.\n");
	
	while (temp != NULL){
	
		count++;
		printf("USN: %s\t", temp -> usn);
		printf("Name: %s\t", temp -> name);
		printf("Branch: %s\t", temp -> branch);
		printf("Semester: %d\t", temp -> sem);
		printf("Phone no. +91%s\n", temp -> phoneno);
		
		temp = temp -> right;
	}
	printf("%d Nodes\n", count);
}


