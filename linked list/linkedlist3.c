#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
   int data;
   struct node *next;
};

int main()
{
struct node *first, *temp;

first=malloc(sizeof(struct node));
temp=first;
temp->next=malloc(sizeof(struct node));
temp=temp->next;
temp->next=malloc(sizeof(struct node));

first->data=111;
first->next->data=222;
first->next->next->data=333;

printf("%d\n",first->data);
printf("%d\n",first->next->data);
printf("%d\n",first->next->next->data);
//free(p);
//printf("%d\n",p->data);
//first->next=second;
//second->next=third;

//printf("\n%d\n", first->next->data);

}