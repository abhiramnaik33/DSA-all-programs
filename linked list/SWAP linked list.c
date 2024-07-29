#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};

int main()
{
	struct node *first, *temp, *T1 , *T2 ;
	int n,  m , v1 ,v2;
	printf("enter the number of nodes you want\n");
	scanf("%d", &n);
	first = malloc(sizeof(struct node));
	temp = first;
	while (n != 1)
	{
		temp->next = malloc(sizeof(struct node));
		temp = temp->next;
		n--;
	}
	temp->next = NULL;
	printf("enter the data for linked list\n");

	temp = first;
	while (temp != NULL)
	{
		scanf("%d", &temp->data);
		temp = temp->next;
	}

	temp = first;
	printf("the elements in linked list are\n ");
	while (temp != NULL)
	{

		printf("%d-->", temp->data);
		temp = temp->next;
	}
	printf("\nwhich node you want to swap\n");
	scanf("%d%d", &v1, &v2);
	//finding the location of the node to be swaped
	temp = first;
	while (temp != NULL)
	{	
		if(v1==temp->data){
			T1=temp;
			break;
		}
		temp = temp->next;
	}
	if(temp==NULL){
		printf("the node with the given information not found");
		exit(0);
	}
	
	//finding the location of the node to be swaped
	temp = first;
	while (temp != NULL)
	{	
		if(v2==temp->data){
			T2=temp;
			break;
		}
		temp = temp->next;
	}
	if(temp==NULL){
		printf("the node with the given information not found");
		exit(0);
	}
	
	m=T1->data;
	T1->data=T2->data;
	T2->data=m;
	
	temp = first;
	printf("the elements in linked list after swaping are\n ");
	while (temp != NULL)
	{

		printf("%d-->", temp->data);
		temp = temp->next;
	}
	
}
