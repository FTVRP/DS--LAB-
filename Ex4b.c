#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Node *createNode(int data)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation error\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void initializeQueue(struct Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

void enqueue(struct Queue *queue, int data)
{
    struct Node *newNode;

    newNode = createNode(data);

    if (queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Element enqueued: %d\n", data);
}

int dequeue(struct Queue *queue)
{
    struct Node *temp;
    int data;

    if (queue->front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }

    temp = queue->front;
    data = temp->data;

    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);

    return data;
}

void displayQueue(struct Queue *queue)
{
    struct Node *temp;

    if (queue->front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = queue->front;

    printf("Queue elements: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    struct Queue queue;
    int choice;
    int element;

    initializeQueue(&queue);

    while (1)
    {
        printf("\nQueue Operations Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter element to enqueue: ");
            scanf("%d", &element);

            enqueue(&queue, element);
        }
        else if (choice == 2)
        {
            element = dequeue(&queue);

            if (element != -1)
            {
                printf("Dequeued element: %d\n", element);
            }
        }
        else if (choice == 3)
        {
            displayQueue(&queue);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }

    return 0;
}