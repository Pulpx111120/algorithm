#include <stdio.h>
#define MaxSize 100000
#define MINVALUE 10000000000

typedef long long KeyType;
typedef struct{
	KeyType Keys[MaxSize];
	int size;
}PriorityQueue;

void swap(KeyType *a, KeyType *b){
	KeyType tmp = *a;
	*a = *b;
	*b = tmp;
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

void minHeapify(PriorityQueue *Q, int i){
	int smallest = 0;
	int l = left(i);
	int r = right(i);
	
	if(l<Q->size && Q->Keys[l]<Q->Keys[i])
		smallest = l;
	else smallest = i;
	
	if(r<Q->size && Q->Keys[r]<Q->Keys[smallest])
		smallest = r;
		
	if(smallest!=i){
		swap(&Q->Keys[smallest], &Q->Keys[i]);
		minHeapify(Q, smallest);
	}
}

void decreaseKey(PriorityQueue *Q, int i, KeyType k){
	if(k>Q->Keys[i]) return;
	Q->Keys[i] = k;
	while(i>0 && Q->Keys[parent(i)]>Q->Keys[i]){
		swap(&Q->Keys[parent(i)], &Q->Keys[i]);
		i=parent(i);
	}
}

void insert(PriorityQueue *Q, KeyType k){
	Q->Keys[Q->size] = MINVALUE;
	decreaseKey(Q, Q->size, k);
	Q->size += 1;
}

KeyType extractMin(PriorityQueue *Q){
	KeyType k = Q->Keys[0];
	swap(&Q->Keys[0], &Q->Keys[Q->size-1]);
	Q->size--;
	minHeapify(Q, 0);
	return k;
}

int main(){
	freopen("tron_hai_danh_sach.inp", "r", stdin);
	int n; scanf("%d", &n);
	PriorityQueue Q;
	KeyType value;
	Q.size = 0;
	int i;
	for(i=0;i<n;i++){
		scanf("%lld", &value);
		insert(&Q, value);
	}
	KeyType result;
	KeyType kq = 0;
	while(Q.size>1){
		result = extractMin(&Q);
		result += extractMin(&Q);
		kq += result;
		insert(&Q, result);
	}
	printf("%lld", kq);
	return 0;
}
