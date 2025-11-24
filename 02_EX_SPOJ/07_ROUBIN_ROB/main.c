#include <stdio.h>
#include <stdlib.h>

struct node
{
    int id;
    int timeToRun;
    int timeToFinish;
    int currentValue;
    struct node* prev;
    struct node* next;
};
typedef struct node Node;

struct queue
{
    Node* front; // Beginning (Dequeue)
    Node* rear; // End (Enqueue)
};
typedef struct queue Queue;

Node* NewNode(int id, int timeToRun, int timeToFinish)
{
    Node* node = malloc(sizeof(Node));
    node->id = id;
    node->timeToRun = timeToRun;
    node->timeToFinish = timeToFinish;
    node->currentValue = 0;
    node->next = NULL;
    node->prev;

    return node;
}

Queue* CreateQueue()
{
    Queue* queue = malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

int GetInt()
{
    int value = 0;
    scanf("%i", &value);
    getchar();

    return value;
}

void Enqueue(Queue* queue, int id, int timeToRun, int timeToFinish)
{
    // 1. Create new process
    Node* newNode = NewNode(id, timeToRun, timeToFinish);

    // 2. Check if the queue is empty
    if(queue->rear == NULL)
    {
        // Queue is empty here, so new node is both front and rear
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        // Queue is not empty insert after the current rear
        newNode->prev = queue->rear;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
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

Node* Peek(Queue* queue)
{
    return queue->front;
}

void ShowQueue(Queue* queue)
{
    Node* currentNode = NULL;
    if(queue != NULL && queue->front != NULL)
    {
        currentNode = queue->front;
    }

    // printf("[");
    while(currentNode != NULL)
    {
        printf("%i", currentNode->id);
        currentNode = currentNode->next;

        if(currentNode != NULL)
        {
             printf(" ");
        }
    }
    // printf("]");
}

int main()
{
    Queue* queue = CreateQueue();
    Queue* queueInProcess = CreateQueue();
    Queue* processFinished = CreateQueue();

    int processAmount = GetInt();
    int quantum = GetInt();

    int currentTime = 0;

    // Temp Vars to input
    int processId = 0;
    int processTimeToStart = 0;
    int processTimeToFinish = 0;

    // Populate the process queue
    for(int i = 0; i < processAmount; i++)
    {
        processId = GetInt();
        processTimeToStart = GetInt();
        processTimeToFinish = GetInt();

        Enqueue(queue, processId, processTimeToStart, processTimeToFinish);

        // Clear the temp vars
        processId = 0;
        processTimeToStart = 0;
        processTimeToFinish = 0;
    }

    Node* currentProcess = NULL;
    Node* process = NULL;
    Node* processAux;

    int processSuccess = 0; // Any process is finished
    while(processSuccess != processAmount)
    {
        processAux = queue->front;

        // Iterate over queue to find the init nodes
        while(processAux != NULL)
        {
            if(processAux->timeToRun == currentTime)
            {
                Enqueue(queueInProcess, processAux->id, processAux->timeToRun, processAux->timeToFinish);
                RefreshQueue(queueInProcess);
            }

            processAux = processAux->next;
        }

        // Process in process queue
        process = Peek(queueInProcess);
        if(process != NULL)
        {
            process->currentValue++;
            if (process->currentValue == process->timeToFinish)
            {
                Enqueue(processFinished, process->id, process->timeToRun, process->timeToFinish);
                Dequeue(queueInProcess);
                processSuccess++;
            }
            
            RefreshQueue(queueInProcess);
        }
        
        currentTime++;
    }

    ShowQueue(processFinished);
    return 0;
}
