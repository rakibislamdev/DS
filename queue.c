#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

struct Queue
{
    int front, rear, capacity;
    int *array;
};

struct Queue *createQueue(int size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = size;
    queue->front = queue->rear = -1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(struct Queue *queue)
{
    return (queue->front == -1);
}

int isFull(struct Queue *queue)
{
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }

    if (isEmpty(queue))
    {
        queue->front = queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }

    queue->array[queue->rear] = item;
    printf("Enqueued %d\n", item);
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return an arbitrary value to indicate an error
    }

    int item = queue->array[queue->front];

    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->capacity;
    }

    printf("Dequeued %d\n", item);
    return item;
}

int main()
{
    struct Queue *myQueue = createQueue(SIZE);

    dequeue(myQueue); // Pass the queue as an argument
    enqueue(myQueue, 7);
    enqueue(myQueue, 5);
    printf("Is the queue empty? %s\n", isEmpty(myQueue) ? "Yes" : "No");

    dequeue(myQueue); // Pass the queue as an argument
    enqueue(myQueue, 2);
    enqueue(myQueue, 1);
    enqueue(myQueue, 0);
    printf("Is the queue full? %s\n", isFull(myQueue) ? "Yes" : "No");

    dequeue(myQueue); // Pass the queue as an argument
    dequeue(myQueue); // Pass the queue as an argument
    dequeue(myQueue); // Pass the queue as an argument

    free(myQueue->array);
    free(myQueue);

    return 0;
}
