#include<stdio.h>
#include<malloc.h>

typedef int KeyType;
typedef struct {
	KeyType *Keys;	//trong so cua canh
	KeyType *u;		//dinh bat dau
	KeyType *v;		//dinh ket thuc
	int size;
}PriorityQueue;

typedef struct {
	int *node;	//cac nut cua do thi, cung la vi tri
	int *parent;	//nut cha cua mot nut, khoi tao = -1
}Parent;

PriorityQueue getQueue () {
	PriorityQueue Q;
	Q.size=0;
	return Q;
}

void swap(KeyType *a, KeyType *b){
	KeyType tmp = *a;
	*a=*b;
	*b=tmp;
}

void minHeapify(PriorityQueue *Q, int m, int i) {
	int l=2*i, r=2*i+1, min=i;
	if(l<Q->size && Q->Keys[min]>Q->Keys[l])
		min=l;
	if(r<Q->size && Q->Keys[min]>Q->Keys[r])
		min=r;
	if(min!=i){
		swap(&Q->Keys[i],&Q->Keys[min]);
		swap(&Q->u[i],&Q->u[min]);
		swap(&Q->v[i],&Q->v[min]);
		minHeapify(Q,Q->size,min);
	}
}

void buildMinHeap(PriorityQueue *Q){
	for(int i=(Q->size-1)/2;i>=1;i--){
		minHeapify(Q,Q->size,i);
	}
}

KeyType extractMin(PriorityQueue *Q){
	KeyType min=Q->Keys[1];
	swap(&Q->Keys[1], &Q->Keys[Q->size]);
	swap(&Q->u[1], &Q->u[Q->size]);
	swap(&Q->v[1], &Q->v[Q->size]);		
	Q->size--;
	minHeapify(Q,Q->size,1);
	return min;
}

int find(int x, Parent &P){
	if (P.parent[x]<0)
		return P.node[x];
	else 
		return find(P.parent[x],P);
	
}

void Union(int x, int y, Parent &P){
	if(P.parent[x]<=P.parent[y]){
		P.parent[x]+=P.parent[y];
		P.parent[y]=P.node[x];
	}
	else {
		P.parent[y]+=P.parent[x];
		P.parent[x]=P.node[y];
	}
}

void Kruskal(int n, int m, Parent &P, PriorityQueue *Q){
	for(int i=1;i<=n;i++){		//khoi tao DisjointSet
		P.parent[i]=-1;
		P.node[i]=i;
	}
	buildMinHeap(Q);
	int i=1, w=0;
	while(i!=m){
		int x = find(Q->u[1], P);
		int y = find(Q->v[1], P);
		if(x!=y){
			Union(x,y,P);
			w+=Q->Keys[1];
		}
		extractMin(Q);
		i++;
	}
	printf("%d", w);
}

void findCost (const char *file) {
	freopen(file, "r", stdin);
	int n, m;
	scanf("%d", &n);	scanf("%d", &m);
	PriorityQueue Q=getQueue();
	Q.size=m;
	Q.Keys = (KeyType*)malloc(Q.size*sizeof(KeyType));
	Q.u = (KeyType*)malloc(Q.size*sizeof(KeyType));
	Q.v = (KeyType*)malloc(Q.size*sizeof(KeyType));
	Parent P;
	P.node = (int*)malloc(n*sizeof(int));
	P.parent = (int*)malloc(n*sizeof(int));
	for(int i=1; i<=Q.size; i++){
		scanf("%d%d%d", &Q.u[i], &Q.v[i], &Q.Keys[i]);	
	}
	Kruskal(n,m,P,&Q);
	
}

int main(){
	const char *file="kruskal02.inp";
	findCost(file);
	return 0;
}

