#include<stdio.h>
#include<malloc.h>
#define MaxSize 100007
typedef struct {
	int Data[MaxSize];
	int Front, Rear;
}Queue;

struct Node{
	int Vertex;		// dinh noi voi dinh do
	int Weight; 	// trong so canh
	struct Node* Next;	// nut ke tiep
};

typedef 	struct Node* AdjList[MaxSize+1];	// mang dsach ke, moi phan tu la 1 con tro node ben tren

void makenullQueue (Queue *Q){
	Q->Front=Q->Rear=0;
}

int emptyQueue (Queue Q){
	return Q.Front==Q.Rear;
}

int fullQueue (Queue Q){
	return (Q.Rear+1) % MaxSize==Q.Front;
}

void enQueue (int x, Queue *Q){
	if(!fullQueue(*Q)){
		Q->Data[Q->Rear]=x;
		Q->Rear=(Q->Rear+1) % MaxSize;
	}
}

void deQueue (Queue *Q, int *top){
	if(!emptyQueue(*Q)){
		(*top)=Q->Data[Q->Front];
		Q->Front=(Q->Front+1) % MaxSize;
	}
}

void printQueue (Queue *Q){
	while(!emptyQueue(*Q)){
		int top;
		deQueue(Q,&top);
		printf("%d", top);
	}
}

AdjList L;
int n, m;
Queue q;

// Khoi tao danh sach ke
void init (AdjList* pL, int n){
	for(int i=0;i<=n;i++){
		(*pL)[i]=(struct Node*)malloc(sizeof(struct Node));
		(*pL)[i]->Next = NULL;
	}
}

// Chen nut j ke voi nut j
void insertNode (AdjList L, int i, int j){
	struct Node* p = (struct Node*)malloc(sizeof(struct Node));
	if(p==NULL){
		return;
	}
	p->Vertex=j;
	p->Next=L[i]->Next;
	L[i]->Next=p;
}

// Kiem tra 2 nut ke nhau
int isAdjacent(int u, int v, AdjList L) {
	struct Node* p = L[u];
	while(p->Next!=NULL){
		if(p->Next->Vertex==v) return 1;
		p=p->Next;
	}
	return 0;
}

void releaseList(struct Node* L1){
	struct Node *q;
	struct Node *p=L1;
	while(p->Next!=NULL){
		q=p->Next;
		p->Next=q->Next;
		free(q);
	}
}

void releaseGraph(AdjList *pL, int N, int M){
	for(int i=0;i<=N;i++){
		releaseList((*pL)[i]);
	}
}

void buildGraph(AdjList *pL, int *pN, int *pM){
	int x,y;
	scanf("%d%d",pN,pM);
	init(pL,*pN);
	for(int i=1;i<=(*pM);i++){
		scanf("%d%d", &x, &y);
		insertNode((*pL),x,y);
		insertNode((*pL),y,x);	 
	}
}

//void printGraph(AdjList L, int N, int M){
//	int x,y;
//	for(int i=1;i<=N;i++){
//		struct Node *p = L[i];
//		printf("Node %d\n",i);
//		while(p->Next!=NULL){
//			printf("\t%d\n",p->Next->Vertex);
//			p=p->Next;
//		}
//	}
//}

int getDistance (int start, int end){	
	int u,v;
	struct Node* p;
	
//	int d[MaxSize], visited[MaxSize];

	int *d, *visited;
	d = (int*)malloc(MaxSize*sizeof(int));
	visited = (int*)malloc(MaxSize*sizeof(int));
	
	for(int i=0;i<MaxSize;i++){
		d[i]=0;
		visited[i]=0;
	}
	makenullQueue(&q);
	enQueue(start,&q);
	visited[start]=1;
	d[start]=0;
	
	while(!emptyQueue(q)){
		deQueue(&q,&u);
		if(u==end) return d[u];
		p=L[u];
		while(p->Next!=NULL){
			v=p->Next->Vertex;
			if(visited[v]==0){
				d[v] = d[u]+1;
				enQueue(v, &q);
				visited[v]=1;
			}
			p=p->Next;
		}
	}
	return d[u];
}

void findShortestPath(const char *file){
	int T;
	freopen(file,"r",stdin);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		buildGraph(&L,&n,&m);
		printf("%d\n",getDistance(1,n));
		for(int j=0;j<=n;j++){
			releaseList(L[i]);
		}
	}
	
}

int main (){
	const char *file="input01.inp";
	findShortestPath(file);
	return 0;
}


