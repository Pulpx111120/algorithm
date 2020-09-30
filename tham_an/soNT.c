#include <stdio.h>
#include <math.h>
#define MaxSize 100000
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

int parent(int i){
	if(i%2==0)
		return (i-2)/2;
	else
		return (i-1)/2;
}

KeyType max(PriorityQueue Q){
	return Q.Keys[0];
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

int ktnt(int n, int d, int c){
	if(c<d)	return 1;
	if(n%d==0) return 0;
	return ktnt(n, d+1, c);
}

int soNT(int n){
	ktnt(n, 2, sqrt(n));
}

int main(){
	int i, n;
	scanf("%d", &n);
	PriorityQueue Q;
	makenull(&Q);
	for(i=0;i<n;i++)
		if(soNT(i))
			insert(&Q, i);
	printf("%d", max(Q));
}
