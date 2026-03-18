#include <stdio.h>

int main()
{
    int queue[5];
    int front = -1, rear = -1;
    int choice, value, i;

    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)  
        {
            if (rear == 4)
            {
                printf("Queue Overflow!\n");
            }
            else
            {
                printf("Enter value: ");
                scanf("%d", &value);

                if (front == -1)
                    front = 0;
                    rear++;
                queue[rear] = value;

                printf("Inserted successfully!\n");
            }
        }
        
          else if (choice == 2)   
        {
            if (front == -1 || front > rear)
            {
                printf("Queue Underflow!\n");
            }
            else
            {printf("Deleted element: %d\n", queue[front]);
                front++;
                if (front > rear)
                {
                    front = rear = -1;
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
                for (i = front; i <= rear; i++)
                {
                    printf("%d ", queue[i]);
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