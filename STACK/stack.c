#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;

void push(int item)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    else
    {
        stack[++top] = item;
        printf("Pushed item is: %d\n", item);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    else
    {
        int item = stack[top--];
        printf("Popped item is: %d\n", item);
    }

    
}

void display()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d\n", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, item;
    while (1)
    {
        printf("1. Push\n"); printf("2. Pop\n"); printf("3. Display\n"); printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to be pushed: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
        printf("----------Display----------\n");
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Error: Invalid choice\n");
        }
    }
    return 0;
}