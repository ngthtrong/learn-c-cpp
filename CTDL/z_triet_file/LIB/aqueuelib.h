#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int Position;
typedef int ElementType;

typedef struct Nodetag{
	ElementType data;
	Nodetag *next;
}Node;

typedef struct{
	Node *front;
	Node *rear;
	Position size;
}Queue;

void makeNull(Queue *Q){
	Q = (Queue*)malloc(sizeof(Queue));
	Q->front = Q->rear = NULL;
	Q->size = 0;
} 

Node *createNode(ElementType x){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

int isEmpty(Queue Q){
	return Q.front->next == Q.rear->next;
}

//int isFull(Queue Q){}

void enQueue(Queue *Q, ElementType x){
	Node *newNode = createNode(x);
	if(isEmpty(*Q)){
		Q->front = Q->rear = newNode;
	}
	else{
		Q->rear->next = newNode;
		Q->rear = newNode; 
	}
	Q->size +=1; 
} 

void deQueue(Queue *Q){
	if(Q->front == NULL){
		printf("Queue is empty!");
	}
	
	Node *temp = Q->front;
	int data = temp->data;
	Q->front = temp->next;
	
	if(Q->front == NULL){
		Q->rear = Q->front = NULL;
	}
	free(temp);
	Q->size -=1;
}
	









