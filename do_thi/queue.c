#include <stdio.h>
#define NSIZE 10007

typedef struct{
	int Nodes[NSIZE];
	int Front, Rear;
}Queue;

void makenullQueue(Queue *pQ){
	pQ->Front = pQ->Rear = 0;
}

int isEmpty(Queue Q){
	return Q.Front == Q.Rear;
}

int isFull(Queue Q){
	return (Q.Rear + 1) % NSIZE == Q.Front;
}

void insertQueue(int X, Queue *pQ){
	if(!isFull(*pQ)){
		pQ->Nodes[pQ->Rear] = X;
		pQ->Rear = (pQ->Rear+1)%NSIZE;
	}
}

void pop(Queue *pQ, int *pTop){
	if(!isEmpty(*pQ)){
		(*pTop) = pQ->Nodes[pQ->Front];
		pQ->Front = (pQ->Front+1)%NSIZE;
	}
}

void print(Queue *pQ){
	while(!isEmpty(*pQ)){
		int top;
		pop(pQ, &top);
		printf("%d\t", top);
	}
	printf("\n");
}
