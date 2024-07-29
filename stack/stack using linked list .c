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
    struct node *top = NULL, *temp;
    int n, x, m, choice;
    do
    {
        printf("Do you want to 1-push, 2-pop, or 3-exit?\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to be pushed\n");
            scanf("%d", &x);
            temp = malloc(sizeof(struct node));
            temp->data = x;
            temp->next = top;//top++
            top = temp;
            printf("Pushed %d\n", x);
            break;
        case 2:
            if (top == NULL)
            {
                printf("stack is empty\n");
            }
            else
            {
//                temp = top;
//                top = top->next;
				temp=temp->next;//shift temp to next and free temp
                printf("the popped element is %d\n", temp->data);
                free(temp);
            }
            break;
        case 3:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice Please try again\n");
        }
    } while (choice != 3);

    return 0;
}

