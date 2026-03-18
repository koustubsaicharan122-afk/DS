#include <stdio.h>

int main()
{
    int queue[5];
    int front = -1, rear = -1;
    int choice, value, i;
    int size = 5;

    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if ((rear + 1) % size == front)
            {
                printf("Queue Overflow!\n");
            }
            else
            {
                printf("Enter value: ");
                scanf("%d", &value);

                if (front == -1)
                {
                    front = rear = 0;
                }
                else
                {
                    rear = (rear + 1) % size;
                }

                queue[rear] = value;
                printf("Inserted successfully!\n");
            }
        }

        else if (choice == 2)
        {
            if (front == -1)
            {
                printf("Queue Underflow!\n");
            }
            else
            {
                printf("Deleted element: %d\n", queue[front]);

                if (front == rear)
                {
                    front = rear = -1;
                }
                else
                {
                    front = (front + 1) % size;
                }
            }
        }

        else if (choice == 3)
        {
            if (front == -1)
            {
                printf("Queue is empty!\n");
            }
            else
            {
                printf("Queue elements: ");
                i = front;

                while (1)
                {
                    printf("%d ", queue[i]);

                    if (i == rear)
                        break;

                    i = (i + 1) % size;
                }

                printf("\n");
            }
        }

        else if (choice == 4)
        {
            break;
        }

        else
        {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}