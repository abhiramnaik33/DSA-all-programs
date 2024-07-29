
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, size = 5, queue[size], rear = -1, front = -1, choice = 0, x = 0;

    while (1) {
        printf("Enter your choice\n 1.Insert\n 2.Delete\n 3.Display\n");
        scanf("%d", &choice);

        if (choice == 1) {
            if (((rear + 1) % size) == front) {
                printf("The queue is full\n");
            } else {
                printf("Enter the number to be inserted into the queue\n");
                scanf("%d", &x);
                if (rear == -1 && front == -1) {
                    front = 0;
                }
                rear = (rear + 1) % size;
                queue[rear] = x;
            }
        } else if (choice == 2) {
            if (front == -1) {
                printf("The Queue is empty\n");
            } else {
                printf("The deleted number is %d\n", queue[front]);
                if (front == rear) {
                    front = rear = -1;
                } else {
                    front = (front + 1) % size;
                }
            }
        } else if (choice == 3) {
            if (front == -1) {
                printf("Queue is empty\n");
            } else {
                printf("Queue elements are:\n");
                for (i = front; i != rear; i = (i + 1) % size) {
                    printf("%d ", queue[i]);
                }
                printf("%d\n", queue[i]);
            }
        } else {
            printf("Wrong Choice\n");
        }
    }

    return 0;
}
