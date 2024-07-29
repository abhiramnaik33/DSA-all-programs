#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int a[MAX_SIZE], top;

void push(int y)
{
    if (top >= 0)
    {
        a[top] = y;
        top--;
        printf("Pushed %d\n", y);
    }
    else
    {
        printf("Stack full\n");
    }
}

int pop()
{
    if (top < MAX_SIZE - 1)
    {
        top++;
        int temp = a[top];
        printf("The popped element is %d\n", temp);
        return temp;
    }
    else
    {
        printf("Stack empty\n");
        return -1; // Return an error value
    }
}

void display()
{
    printf("Stack contents:\n");
    for (int i = top + 1; i < MAX_SIZE; i++)
    {
        printf("|%d|\n", a[i]);
    }
    printf("\n");
}

int main()
{
    int choice = 0, x;

    top = MAX_SIZE - 1;

    while (1)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number to be pushed\n");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
