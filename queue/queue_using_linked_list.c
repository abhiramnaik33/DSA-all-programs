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
    struct node *front = NULL, *rear = NULL, *temp; // intialting front and rare with NULL and createing a temp variable
    int x, choice;

    do
    {
        printf("Do you want to 1-enqueue, 2-dequeue, or 3-exit?\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to be enqueued\n");
            scanf("%d", &x);
            temp = malloc(sizeof(struct node)); // allocating memory
            temp->data = x;
            temp->next = NULL;
            // if (rear == NULL)
            // {
            //     front = rear = temp; // if rare is null equate all 3 parameters
            // }
            // else
            // {
            //     rear->next = temp; // if not then equate rare next is equal to temp
            //     rear = temp;
            // }
            printf("Enqueued %d\n", x);
            break;
        case 2:
            if (front == NULL) //-1
            {
                printf("Queue is empty\n");
            }
            else
            {
                temp = front;        // put the front pointer to next
                temp = temp->next; // temp is made for traversal purpose
                printf("The dequeued element is %d\n", temp->data);
                free(temp);
            }
            break;
        case 3:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
