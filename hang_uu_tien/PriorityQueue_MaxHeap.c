#include <stdio.h>
#define MaxSize 100
#define MINVALUE -32768

typedef int KeyType;
typedef struct{
	KeyType Keys[MaxSize];
	int size;
}PriorityQueue;

void swap(KeyType *a, KeyType *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void makenull(PriorityQueue *Q){
	Q->size=0;
}

int left(int i){
	return 2*i+1;
}

int right(int i){
	return 2*i+2;
}

int parent(int i){
	if(i%2==0)
		return (i-2)/2;
	else
		return (i-1)/2;
}

PriorityQueue getQueue(){
	PriorityQueue Q;
	Q.size = 0;
	return Q;
}

int isEmpty(PriorityQueue Q){
	return Q.size==0;
}

KeyType max(PriorityQueue Q){
	return Q.Keys[0];
}

void maxHeapify(PriorityQueue *Q, int i){
	int largest = 0;
	int l = left(i);
	int r = right(i);
	
	if(l<Q->size && Q->Keys[l]>Q->Keys[i])
		largest = l;
	else largest = i;
	
	if(r<Q->size && Q->Keys[r]>Q->Keys[largest])
		largest = r;
		
	if(largest!=i){
		swap(&Q->Keys[largest], &Q->Keys[i]);
		maxHeapify(Q, largest);
	}
}

void buildMaxHeap(PriorityQueue *Q){
	int i;
	for(i=(Q->size-1)/2;i>=0;i--){
		maxHeapify(Q, i);
	}
}

void printHeap(PriorityQueue Q){
	int i;
	for(i=0;i<=Q.size-1;i++)
		printf("%d ", Q.Keys[i]);
	printf("\n");
}

void increaseKey(PriorityQueue *Q, int i, KeyType k){
	if(k<Q->Keys[i]) return;
	Q->Keys[i] = k;
	while(i>0 && Q->Keys[parent(i)]<Q->Keys[i]){
		swap(&Q->Keys[parent(i)], &Q->Keys[i]);
		i=parent(i);
	}
}

void insert(PriorityQueue *Q, KeyType k){
	Q->Keys[Q->size] = MINVALUE;
	increaseKey(Q, Q->size, k);
	Q->size += 1;
}

KeyType extractMax(PriorityQueue *Q){
	int k=Q->Keys[0];
	swap(&Q->Keys[0], &Q->Keys[Q->size-1]);
	Q->size--;
	maxHeapify(Q, 0);
	return k;
}

int main(){
	PriorityQueue Q;
	makenull(&Q);
	insert(&Q, 5);
	insert(&Q, 10);
	insert(&Q, 100);
	insert(&Q, 80);
	insert(&Q, 90);
	insert(&Q, 167);
	insert(&Q, 85);
	insert(&Q, 95);
	printHeap(Q);
	return 0;
}
