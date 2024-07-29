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
	struct node *first, *temp;
	int n, m;
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
}
