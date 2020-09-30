#include <stdio.h>
#include <malloc.h>
#include "queue.c"
#define NSIZE 10007

//
struct Node{
	int Vertex;
	int Weight;
	struct Node* Next;
};

typedef struct Node* AdjList[NSIZE+1];

//Global variables
AdjList L;
int n, m; //n dinh, m canh
Queue q;

int visited[NSIZE];

//
void init(AdjList* pL, int n){
	int i;
	for(i=0;i<=n;i++){
		(*pL)[i] = (struct Node*)malloc(sizeof(struct Node));
		(*pL)[i]->Next = NULL;
	}
}

//enQueue nut j la ke voi nut i
void insertNode(AdjList L, int i, int j, int weight){
	struct Node* p = (struct Node*)malloc(sizeof(struct Node));
	if(p==NULL){
		printf("O day ha");
		return ;
	}
	//return 0;
	p->Vertex = j;
	p->Weight = weight;
	p->Next = L[i]->Next;
	L[i]->Next = p;
}

int isAdjacent(int u, int v, AdjList L){
	struct Node* p = L[u];
	while(p->Next!=NULL){
		if(p->Next->Vertex==v) return 1;
		p = p->Next;
	}
	return 0;
}

void releaseList(struct Node* L1){
	struct Node *q;
	struct Node *p = L1;
	while(p->Next!=NULL){
		q = p->Next;
		p->Next = q->Next;
		free(q);
	}
}

void buildGraph(AdjList *pL, int *pN, int *pM){
	int i;
	int x, y, w;
	scanf("%d%d", pN, pM);
	init(pL, *pN);
	for(i=1;i<=(*pM);i++){
		scanf("%d%d", &x, &y);
		w = 1;
		insertNode((*pL), x, y, w);
		insertNode((*pL), y, x, w);
	}
}

void printGraph(AdjList L, int N, int M){
	int i, j;
	int x, y, w;
	for(i=1;i<=N;i++){
		struct Node *p = L[i];
		printf("Node %d\n", i);
		while(p->Next!=NULL){
			printf("\t%d\t%d\n", p->Next->Vertex, p->Next->Weight);
			p = p->Next;
		}
	}
}

//BFS
void doDFS(int start){
	struct Node *p; 
	p = L[start];
	visited[start] = 1;
	while(p->Next!=NULL){
		int u = p->Next->Vertex;
		if(!visited[u])
			doDFS(u);
		p = p->Next;
	}
}

int getDistance(int start, int end){
	int i;
	int u, v;
	struct Node* p;
	int d[NSIZE], visited[NSIZE];
	
	for(i=0;i<NSIZE;i++){
		d[i] = 0;
		visited[i] = 0;
	}
	
	makenullQueue(&q);
	insertQueue(start, &q);
	visited[start] = 1;
	d[start] = 0;
	
	while(!isEmpty(q)){
		pop(&q, &u);
		if(u==end) return d[u];
		p = L[u];
		while(p->Next!=NULL){
			v = p->Next->Vertex;
			if(visited[v]==0){
				d[v] = d[u]+1;
				insertQueue(v, &q);
				visited[v] = 1;
			}
			p = p->Next;
		}
	}
	return d[u];
}

//void solve(){
//	int start, i, count;
//	
//	buildGraph(&L, &n, &m);
//	for(i=0;i<NSIZE;i++)
//		visited[i] = 0;
//	scanf("%d", &start);
//	doDFS(start);
//	count = 0;
//	for(i=0;i<NSIZE;i++)
//		if(visited[i]) count++;
//	printf("%d", n-count);
//}

//void solve(){
//	int T, i, j;
//	
//	scanf("%d", &T);
//	for(i=1;i<=T;i++){
//		buildGraph(&L, &n, &m);
//		printf("%d\n", getDistance(1, n));
//		for(j=0;j<=n;j++)
//			releaseList(L[i]);
//	}
//}


