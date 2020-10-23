#include <stdio.h>
#define MAX_ELEMENTS 100
#define MAX_VERTICES 100

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
int num[MAX_VERTICES]; // luu chi so cua dinh v trong qua trinh duyet
int min_num[MAX_VERTICES]; // Luu chi so nho nhat cua nut co the di den duoc tu v
Stack S; // Ngan xep, luu cac dinh theo thu tu duoc duyet
int on_stack[MAX_VERTICES]; // v co dang o trong stack S hay khong
int v, k, count = 0;

int min (int a, int b) {
	return (a < b) ? a : b;
}

/* Duyet do thi bat dau tu dinh x */
void strong_connect (Graph* G, int x) {
	num[x] = min_num[x] = k; k++;
	push(&S, x);
	on_stack[x] = 1;
	
	List list = neighbors(G, x);
	int j;
	/* Xet cac dinh ke cua no */
	for (j = 1; j <= list.size; j++) {
		int y = element_at(&list, j);
		if (num[y] < 0) {
			strong_connect(G, y);
			min_num[x] = min(min_num[x], min_num[y]);
		} else if (on_stack[y])
			min_num[x] = min(min_num[x], num[y]);
	}
//	printf("min_num[%d] = %d\n", x, min_num[x]);
	
	if (num[x] == min_num[x]) {
//		printf("%d la dinh khop.\n", x);
		count++;
		int w;
		do {
			w = top(&S);
			pop(&S);
			on_stack[w] = 0;
		} while (w != x);
	}
}

/****************************************************************************************/
int main() {
	Graph G;
	int n, m, i;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (i = 0; i < m; i++) {
		int a, b, p; scanf("%d%d%d", &a, &b, &p);
		if (p == 1) G.A[a][b] = p;
		else {
			G.A[a][b] += 1;
			G.A[b][a] += 1;
		}
	}
	for (v = 1; v <= n; v++) {
		num[v] = -1;
		on_stack[v] = 0;
	}
	k = 1;
	make_null_stack(&S);
	
	for (v = 1; v <= n; v++)
		if (num[v] == -1)
			strong_connect(&G, v);
	if (count == 1) printf("OKIE");
	else printf("NO");
	return 0;
}