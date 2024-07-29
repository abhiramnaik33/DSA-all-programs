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
	int n, count = 0, m;
	printf("enter the number of nodes for doubly  you want\n");
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
	printf("enter the data for doubly linked list\n");

	temp = first;
	while (temp != NULL)
	{
		scanf("%d", &temp->data);
		temp = temp->next;
	}

	temp = first;
	printf("\nthe elements in doubly linked listin forward dirction  are\n ");
	while (temp != NULL)
	{

		printf("%d-->", temp->data);
		//to capture the last node 
		if(temp->next==NULL){
			last=temp;
		}
		temp = temp->next;
	}
	temp=last;
	printf("\nthe elements in doubly linked listin backward dirction  are\n ");
	while (temp != NULL)
	{

		printf("%d-->", temp->data);
		temp = temp->prev;
	}
}
