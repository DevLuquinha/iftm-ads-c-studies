#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node
{
    int id;
    struct node* prev;
    struct node* next;
};
typedef struct node Node;

struct queue
{
    Node* front;
    Node* rear;
};
typedef struct queue Queue;

int GetInt()
{
    int num = 0;
    scanf("%i", &num);

    return num;
}

Queue* CreateQueue()
{
    Queue* queue = malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

Node* CreateNode(int id)
{
    Node* node = malloc(sizeof(Node));
    node->id = id;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

// void ShowQueue(Queue* queue)
// {
//     Node* initNode = NULL;
//     if(queue != NULL)
//     {
//         initNode = queue->front;
//     }

//     // printf("[");
//     while (initNode != NULL)
//     {
//         printf("%i", initNode->id);
//         initNode = initNode->next;
//         if(initNode != NULL)
//         {
//             printf(" ");
//         }
//     }
//     // printf("]");

// }

Node* ShowQueue(Node* node)
{
    if(node == NULL)
    {
        return NULL;
    }
    else
    {
        printf("%i ", node->id);
        return ShowQueue(node->next);
    }
}

void Enqueue(Queue* queue, int id)
{
    // 1. Create the New Node
    Node* newNode = CreateNode(id);

    // 2. Check if the queue is empty
    if(queue->rear == NULL)
    {
        // Queue is empty, so the newNode is both front and rear
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        // Queue is not empty, insert after the current rear
        newNode->prev = queue->rear;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void Dequeue(Queue* queue)
{
    if(queue->front != NULL)
    {
        // 1. Save the node to be deleted
        Node* temp = queue->front;

        // 2. Move the front pointer to the next node
        queue->front = queue->front->next;

        // 3. Check if the queue became empty
        if(queue->front == NULL)
        {
            queue->rear = NULL;
        }
        else
        {
            queue->front->prev = NULL;
        }

        free(temp);
    }
}

int Peek(Queue* queue)
{
    if(queue->front == NULL)
    {
        // Queue is empty
        return -1;
    }

    // Return the id of the first elem 
    return queue->front->id;
}

void RefreshQueue(Queue* queue)
{
    // 1. Verify if queue is empty
    if(queue != NULL && queue->front != NULL)
    {
        // 2. Verify if the queue has one value
        if(queue->front != queue->rear)
        {
            Node* frontAux = queue->front; // 11h

            queue->front = queue->front->next;
            queue->front->prev = NULL;

            frontAux->next = NULL;
            frontAux->prev = queue->rear;
            queue->rear->next = frontAux;
            queue->rear = frontAux;
        }
    }
} 

int main()
{
    Queue* originalPeopleQueue = CreateQueue();
    Queue* peopleOutQueue = CreateQueue();

    int originalQueueAmount = GetInt();
    int personId = 0;

    // Get the OriginalPeopleQueue
    for(int i = 0; i < originalQueueAmount; i++)
    {
        personId = GetInt();
        Enqueue(originalPeopleQueue, personId);
    }

    int peopleOutAmount = GetInt();

    // Get the PeopleOutQueue
    for(int i = 0; i < peopleOutAmount; i++)
    {
        personId = GetInt();
        Enqueue(peopleOutQueue, personId);
    }
    
    // Peek the First person in original queue 
    int originPersonId = Peek(originalPeopleQueue);
    int personOutId = -1;
    int isPersonRemoved = 0; // False

    for(int j = 0; j < originalQueueAmount; j++)
    {
        isPersonRemoved = 0; // Foreach person, default is not removed

        // Verify if the id in peopleOut
        for(int i = 0; i < peopleOutAmount; i++)
        {
            personOutId = Peek(peopleOutQueue);
            if (originPersonId == personOutId)
            {
                Dequeue(originalPeopleQueue);
                isPersonRemoved = 1; // The person is removed
            }

            RefreshQueue(peopleOutQueue);
        }

        if(isPersonRemoved == 0)
        {
            RefreshQueue(originalPeopleQueue);
        }

        originPersonId = Peek(originalPeopleQueue);
    }
    
    ShowQueue(originalPeopleQueue->front);
    
    return 0;
}