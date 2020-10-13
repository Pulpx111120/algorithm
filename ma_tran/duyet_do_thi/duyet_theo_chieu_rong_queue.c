#include <stdio.h>
#define MAX_VERTICES 100
#define MAX_ELEMENTS 100

/***************************************** Graph *****************************************/
typedef struct {
	int n; /* n: so dinh */
	/* ma tran dinh - dinh */
	int A[MAX_VERTICES][MAX_VERTICES];
} Graph;

/* Khoi tao do thi G co n dinh */
void init_graph (Graph* G, int n) {
	int i, j;
	G->n = n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			G->A[i][j] = 0;
}

/* Them cung e = (x, y) vao do thi G */
void add_edge (Graph* G, int x, int y) {
	G->A[x][y] = 1; //y ke voi x
	G->A[y][x] = 1; //x ke voi y
}

/* Them cung e = (x, y) vao do thi G, truong hop da cung */
void add_edges (Graph* G, int x, int y) {
	G->A[x][y] += 1; //y ke voi x
	G->A[y][x] += 1; //x ke voi y
}

/* Kiem tra y co ke voi x khong */
int adjacent (Graph* G, int x, int y) {
	return G->A[x][y] != 0;
}

/* Tinh bac cua dinh x: deg(x) */
int degree (Graph* G, int x) {
	int y, deg = 0;
	for (y = 1; y <= G->n; y++)
		if (G->A[x][y] > 0)
			deg++;
	return deg;
}

/* Tinh bac cua dinh x: deg(x), truong hop da cung */
int degrees (Graph* G, int x) {
	int y, deg = 0;
	for (y = 1; y <= G->n; y++)
		deg += G->A[x][y];
	return deg;
}

/****************************************************************************************/
/***************************************** List *****************************************/
typedef int ElementType;

typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
} List;

/* Tao danh sach rong */
void make_null (List* L) {
	L->size = 0;
}

/* Them mot phan tu vao cuoi danh sach */
void push_back (List* L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}

/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
ElementType element_at (List* L, int i) {
	return L->data[i-1];
}

/* Tra ve so phan tu cua danh sach */
int count_list (List* L) {
	return L->size;
}

/* Tim cac dinh ke cua dinh x */
List neighbors (Graph* G, int x) {
	int i;
	List L;
	make_null(&L);
	for (i = 1; i <= G->n; i++)
		if (adjacent(G, x, i))
			push_back(&L, i);
	return L;
}

/****************************************************************************************/
/***************************************** Queue ****************************************/
typedef struct {
	int data[MAX_ELEMENTS];
	int front, rear;
} Queue;

/* Tao Queue rong */
void make_null_queue (Queue* Q) {
	Q->front = 0;
	Q->rear = -1;
}

/* Dua phan tu vao cuoi Queue */
void push (Queue* Q, int x) {
	Q->rear++;
	Q->data[Q->rear] = x;
}

/* Tra ve phan tu dau Queue */
int top (Queue* Q) {
	return Q->data[Q->front];
}

/* Xoa phan tu dau Queue */
void pop (Queue* Q) {
	Q->front++;
}

/* Kiem tra Queue rong */
int empty (Queue* Q) {
	return Q->front > Q->rear;
}

/* Duyet do thi theo chieu rong */
void breath_first_search (Graph* G) {
	Queue frontier;
	int mark[MAX_VERTICES];
	make_null_queue(&frontier);
	
	/* Khoi tao mark, chua dinh nao duoc xet */
	int j;
	for (j = 1; j <= G->n; j++)
		mark[j] = 0;
		
	/* Dua 1 vao frontier: Truong hop xet tu dinh dau tien */
	printf("Xet tu dinh 1\n");
	push(&frontier, 1);
	
	/* Duyet 1 */
	printf("Duyet 1\n");
	mark[1] = 1;
	
	/* Nhap vao dinh can xet: Truong hop nhap */
//	int x; scanf("%d", &x); printf("Xet tu dinh %d\n", x);
//	push(&frontier, x);
//	mark[x] = 1;
	
	/* Vong lap chinh dung de duyet */
	while (!empty(&frontier)) {
		/* Lay phan tu dau tien trong frontier ra */
		int x = top(&frontier); pop(&frontier);
		/* Lay cac dinh ke cua no */
		List list = neighbors(G, x);
		/* Xet cac dinh ke cua no */
		for (j = 1; j <= list.size; j++) {
			int y = element_at(&list, j);
			if (mark[y] == 0) { // y chua duyet, duyet no
				printf("Duyet %d\n", y);
				mark[y] = 1; // Danh dau y da duyet
				push(&frontier, y); // Dua vao hang doi de lat nua xet
			}
		}
	}
}

/****************************************************************************************/