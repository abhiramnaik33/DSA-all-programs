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
   struct node *first;

   first = malloc(sizeof(struct node));
   first->next = malloc(sizeof(struct node));
   first->next->next = malloc(sizeof(struct node));

   first->data = 111;
   first->next->data = 222;
   first->next->next->data = 333;

   printf("%d\n", first->data);
   printf("%d\n", first->next->data);
   printf("%d\n", first->next->next->data);

   free(first->next->next);
   free(first->next);
   free(first);
}
