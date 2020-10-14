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

/***************************************** Stack *****************************************/
typedef struct {
	int data[MAX_ELEMENTS];
	int size;
} Stack;

/* Tao Stack rong */
void make_null_stack (Stack* S) {
	S->size = 0;
}

/* Them phan tu vao dau Stack */
void push (Stack* S, int x) {
	S->data[S->size] = x;
	S->size++;
}

/* Tra ve phan tu dau Stack */
int top (Stack* S) {
	return S->data[S->size - 1];
}

/* Xoa phan tu dau Stack */
void pop (Stack* S) {
	S->size--;
}

/* Kiem tra Stack rong */
int empty (Stack* S) {
	return S->size == 0;
}

/* Bien ho tro */
int mark[MAX_VERTICES];

/* Duyet do thi theo chieu sau */
void depth_first_search (Graph* G, int x) {
	Stack frontier;
	make_null_stack(&frontier);
	
	/* Khoi tao mark, chua dinh nao duoc xet */
	int i, j;
		
	push(&frontier, x);
	
	/* Vong lap chinh dung de duyet */
	while (!empty(&frontier)) {
		/* Lay phan tu dau tien trong frontier ra */
		int x = top(&frontier); pop(&frontier);
		if (mark[x] != 0) // Da duyet roi, bo qua
			continue;
		printf("Duyet %d\n", x);
		mark[x] = 1; // Danh dau no da duyet
		/* Lay cac dinh ke cua no */
		List list = neighbors(G, x);
		/* Xet cac dinh ke cua no */
		for (j = 1; j <= list.size; j++) {
			int y = element_at(&list, j);
			push(&frontier, y);
		}
	}
	
	for (i = 1; i <= G->n; i++)
		if (mark[i] == 0)
			depth_first_search(G, i);
}

/****************************************************************************************/
int main() {
	freopen("test1.inp", "r", stdin);
	Graph G;
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		add_edge(&G, a, b);
	}
	for (j = 1; j <= G.n; j++)
		mark[j] = 0;
//	for (i = 1; i <= m; i++)
//		printf("deg(%d) = %d\n", i, degree(&G, i));
//	for (i = 1; i <= n; i++) {
//		List L = neighbors(&G, i);
//		printf("Cac dinh ke cua %d: [ ", i);
//		for (j = 1; j <= L.size; j++)
//			printf("%d ", element_at(&L, j));
//		printf("]\n");
//	}
	depth_first_search(&G, 1);
	return 0;
}	
