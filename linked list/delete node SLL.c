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
int n,  m , v;
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
printf("\nwhich node you want to delete\n");
scanf("%d", &v);
//finding the location of the node to be deleted
T1 = first;
while (T1 != NULL)
{
if(v==T1->data){
break;
}
T1 = T1->next;
}
T2 = first;
while (T2 != NULL)
{
if(T2->next==T1){
break;
}
T2 = T2->next;
}

T2->next=T1->next;
free(T1);
temp = first;
printf("the elements in linked list are\n ");
while (temp != NULL)
{
printf("%d-->", temp->data);
temp = temp->next;
}
}
