#include <stdio.h>
#define MaxSize 100
#define MINVALUE 32768

typedef int KeyType;
typedef struct {
	KeyType Keys[MaxSize];
	int size;
} PriorityQueue;

void swap (KeyType *a, KeyType *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void makenull (PriorityQueue *Q) {
	Q->size = 0;
}

int left (int i) {
	return 2 * i + 1;
}

int right (int i) {
	return 2 * i + 2;
}

int parent (int i) {
	if (i % 2 == 0) return (i - 2) / 2;
	else return (i - 1) / 2;
}

PriorityQueue getQueue () {
	PriorityQueue Q;
	Q.size = 0;
	return Q;
}

int isEmpty (PriorityQueue Q) {
	return Q.size == 0;
}

KeyType min (PriorityQueue Q) {
	return Q.Keys[0];
}

void minHeapify (PriorityQueue *Q, int i) {
	int smallest = 0;
	int l = left(i);
	int r = right(i);
	
	if (l < Q->size && Q->Keys[l] < Q->Keys[i])
		smallest = l;
	else smallest = i;
	
	if (r < Q->size && Q->Keys[r] < Q->Keys[smallest])
		smallest = r;
		
	if (smallest != i){
		swap(&Q->Keys[smallest], &Q->Keys[i]);
		minHeapify(Q, smallest);
	}
}

void buildMinHeap (PriorityQueue *Q) {
	int i;
	for (i = (Q->size - 1) / 2; i >= 0; i--){
		minHeapify(Q, i);
	}
}

void printHeap (PriorityQueue Q) {
	int i;
	for (i = 0; i <= Q.size - 1; i++)
		printf("%d ", Q.Keys[i]);
	printf("\n");
}

void decreaseKey (PriorityQueue *Q, int i, KeyType k) {
	if (k > Q->Keys[i]) return;
	Q->Keys[i] = k;
	while (i > 0 && Q->Keys[parent(i)] > Q->Keys[i]){
		swap(&Q->Keys[parent(i)], &Q->Keys[i]);
		i = parent(i);
	}
}

void insert (PriorityQueue *Q, KeyType k) {
	Q->Keys[Q->size] = MINVALUE;
	decreaseKey(Q, Q->size, k);
	Q->size += 1;
}

KeyType extractMin (PriorityQueue *Q) {
	int k = Q->Keys[0];
	swap(&Q->Keys[0], &Q->Keys[Q->size - 1]);
	Q->size--;
	minHeapify(Q, 0);
	return k;
}

void sort (PriorityQueue *Q) {
	int n = Q->size;
	while (!isEmpty(*Q))
		KeyType k = extractMin(Q);
	Q->size = n;
}

void solve (PriorityQueue *Q) {
	long long k1, k2, k = 0;
	while (1) {
		k1 = extractMin(Q);
		k2 = extractMin(Q);
		k += (k1+k2);
		if (isEmpty(*Q))
			break;
		insert(Q, k1 + k2);
	}
}

int main() {
	PriorityQueue Q;
	makenull(&Q);
	insert(&Q, -1);
	insert(&Q, 10);
	insert(&Q, 8);
	insert(&Q, 9);
	insert(&Q, 7);
	insert(&Q, 6);
	insert(&Q, 5);
	insert(&Q, 4);
//	buildMaxHeap(&Q);
	printHeap(Q);
	return 0;
}