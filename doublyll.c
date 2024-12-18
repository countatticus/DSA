#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char usn[15];
	char name[20];
	char branch[10];
	int sem;
	char phoneno[15];
	
	struct node *right;
	struct node *left;
} *NODE;

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
		printf("\nSTUDENT DETAILS (REMOVED): \n");
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
	
	printf("\nSTUDENT DETAILS (REMOVED): \n");
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
		printf("\nSTUDENT DETAILS (REMOVED): \n");
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
	
	printf("\nSTUDENT DETAILS (REMOVED): \n");
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
	//printf("Student Details: \n");
	//printf("USN\t\tName\t\tBranch\t\tSemester\t\tPhone no.\n");
	
	 printf("\nSTUDENT DETAILS \n");
    	printf("%-10s %-20s %-8s %-9s %-15s\n", "USN", "Name", "Branch", "Semester", "Phone no.");
    	printf("--------------------------------------------------------------------\n");
	
	while (temp != NULL){
	
		count++;
		
		/*
		printf("%s\t\t", temp -> usn);
		printf("%s\t\t", temp -> name);
		printf("%s\t\t", temp -> branch);
		printf("%d\t\t", temp -> sem);
		printf("+91%s\n", temp -> phoneno);
		*/
		
		printf("%-10s %-20s %-8s %-9d +91%-15s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phoneno);
		
		temp = temp -> right;
	}
	printf("--------------------------------------------------------------------\n");
	printf("%d Node(s)\n", count);
}

int main(){

	int choice;
	char usn[15], name[20], branch[10], phoneno[15];
	int sem;
	
	NODE first = NULL;
	
	while(1){
		printf("\nMenu \n");
		printf("FRONT: 1. Insert 2. Delete\n");
		printf("REAR: 3. Insert 4. Delete\n");
		printf("5. Display \n6. Exit\n");
		
		printf("Enter choice: ");
		scanf("%d", &choice);
		
		/*2 ways of accepting user input: 
		    1. Using scanf("%d", &<variable_name>);: Reads until next whitespace, not best for multiwords
		    2. Using fgets (name, sizeof(name), stdin): Solves whitespace problem
		*/
		
		switch(choice){
			case 1:
				printf("\nENTER STUDENT DETAILS \n");
				printf("USN: ");
				scanf("%s", usn);
				printf("Name: ");
				scanf("%s", name);
				printf("Branch: ");
				scanf("%s", branch);
				printf("Semester: ");
				scanf("%d", &sem);
				printf("Phone no.: ");
				scanf("%s", phoneno);
				
				first = insert_front(usn, name, branch, sem, phoneno, first);
				break;
			case 2:
				first = del_front(first);
				break;
			case 3:
				printf("\nENTER STUDENT DETAILS \n");
				printf("USN: ");
				scanf("%s", usn);
				printf("Name: ");
				scanf("%s", name);
				printf("Branch: ");
				scanf("%s", branch);
				printf("Semester: ");
				scanf("%d", &sem);
				printf("Phone no.: ");
				scanf("%s", phoneno);
				
				first = insert_rear(usn, name, branch, sem, phoneno, first);
				break;
			case 4:
				first = del_rear(first);
				break;
			case 5: 
				display(first);
				break;
			case 6:
				exit(0);
			default: printf("Please enter a valid choice. \n");
		}
	}
	return 0;
}
