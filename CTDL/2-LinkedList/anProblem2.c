#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxlength 100
typedef struct
{
    char data[50];
} ElementType;
typedef struct CellTag
{
    char element[Maxlength];
    struct CellTag *next;
} Cell;
typedef Cell *Position;
typedef struct
{
    Position front, rear;
} Queue;
void makeNull(Queue *pQ)
{
    Position Header = (Position)malloc(sizeof(Cell));
    Header->next = NULL;
    pQ->front = Header;
    pQ->rear = Header;
}
int empty(Queue *pQ)
{
    return (pQ->front == pQ->rear);
}
void dequeue(Queue *pQ)
{
    if (pQ->front == pQ->rear)
    {
        return;
    }
    else
    {
        Position temp = (pQ)->front;
        (pQ)->front = pQ->front->next;
        free(temp);
    }
}
void enqueue(char x[], Queue *pQ)
{
    pQ->rear->next = malloc(sizeof(Cell));
    strcpy(pQ->rear->next->element, x);
    pQ->rear->next->next = NULL;
    pQ->rear = pQ->rear->next;
}
int main()
{
    Queue Q;
    makeNull(&Q);
    char c[100];
    ElementType command;
    while (1)
    {
        scanf("%s", command.data);
        if (strcmp(command.data, "ADD") == 0)
        {
            scanf("%s", c);
            enqueue(c, &Q);
        }
        if (strcmp(command.data, "PRINT") == 0)
        {
            if (empty(&Q))
            {
                printf("Queue is empty, cannot print.\n");
            }
            else
            {
                printf("Print %s\n", Q.front->next->element);
                dequeue(&Q);
            }
        }
        if (strcmp(command.data, "CANCEL") == 0)
        {
            if (empty(&Q))
            {
                printf("Queue is empty, cannot cancel.\n");
            }
            else
            {
                printf("Delete %s\n", Q.front->next->element);
                dequeue(&Q);
            }
        }
        if (strcmp(command.data, "DONE") == 0)
        {
            break;
        }
    }
}