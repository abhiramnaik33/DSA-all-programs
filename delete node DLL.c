#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next , *prev ;
};

int main()
{
	struct node *first, *temp , *last;
	int n,v;
	printf("enter the number of nodes for doubly linked list ?\n");
	scanf("%d", &n);
	first = malloc(sizeof(struct node));
	first->next = NULL;
	first->prev= NULL;
	temp = first;
	while (n != 1)
	{
		temp->next = malloc(sizeof(struct node));
		temp->next->prev = temp;
		temp = temp->next;
		n--;
	}
	temp->next = NULL;
	printf("Enter the data for DOUBLY LINKED LIST list\n");

	temp = first;
	while (temp != NULL)
	{
		scanf("%d", &temp->data);
		temp = temp->next;
	}

	temp = first;
	printf("\nThe elements in doubly linked list in forward direction are\n ");
	while (temp != NULL)
	{

		printf("%d-->", temp->data);
//		if(temp->next==NULL){
//			last=temp;
//		}
//		temp = temp->next;
//	}
//	temp=last;
//	printf("\nthe elements in doubly linked listin backward dirction  are\n ");
//	while (temp != NULL)
//	{
//		printf("%d-->", temp->data);
//		temp = temp->prev;
//	}

	printf("\nenter the node to be deleted\n");
	scanf("%d",&v);
	

	
	
	//finding the location of the node to be deleted
	temp=first;
	while (temp != NULL){
	
//	{	if(v==first->data){
//		//printf("hey u can't delete the frist element\n");
//		first = first->next;
//		first->prev = NULL;
//		free(temp);
//		 	break;
	}
		 if(v==temp->data){
		 	temp->prev->next = temp->next;
		 	temp->next->prev =temp->prev;
		 	break;
		}

		   temp = temp->next;
}

	temp = first;
	printf("\nThe elements in doubly linked list in forward dirction after deleteing the node are:\n ");
	while (temp != NULL)
	{

		printf("%d-->", temp->data);
		//to capture the last node 
		if(temp->next==NULL){
			last=temp;
		}
		temp = temp->next;
	}
}

//case 1 a number in the ll is taken which in result is deleted 
//case 2 the frist number is taken as input which is deleted 
//case 3 the number which does not eixsts is taken as input 
