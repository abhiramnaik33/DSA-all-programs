#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
   int data;
   struct node *next;
};

int main()
{
struct node *first, *second, *third;

first=malloc(sizeof(struct node));
second=malloc(sizeof(struct node));
third=malloc(sizeof(struct node));

first->data=111;
second->data=222;
third->data=333;

printf("%d\n",first->data);
printf("%d\n",second->data);
printf("%d\n",third->data);
//free(p);
//printf("%d\n",p->data);
first->next=second;
second->next=third;

printf("\n%d\n", first->next->data);

}
