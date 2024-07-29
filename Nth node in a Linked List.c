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
	int n, count = 0, m;
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

	printf("\nprint which node you want from the end of linked list\n");
	scanf("%d", &m);
	temp = first;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
//	printf("%d\n", count);
	temp = first;
	while ((count - m) != 0)
	{
		count--;
		temp = temp->next;
	}
	printf("the information in the node asked by you is %d\n", temp->data);
}
