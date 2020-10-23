#include <stdio.h>
#define MAX_VERTICES 100 //Dinh
#define MAX_EDGES 500 //Cung
#define MAX_ELEMENTS 100

/***************************************** Graph *****************************************/
typedef struct {
	int n, m; /* n: so dinh, m: so cung */
	int A[MAX_VERTICES][MAX_EDGES];
} Graph;

/* Khoi tao do thi G co n dinh, m cung */
void init_graph (Graph* G, int n, int m) {
	int i, j;
	G->n = n;
	G->m = m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			G->A[i][j] = 0;
}

/* Them cung e = (x, y) vao do thi G */
void add_edge (Graph* G, int e, int x, int y) {
	G->A[x][e] = 1; //x lien thuoc voi e
	G->A[y][e] = 1; //y lien thuoc voi e
}

/* Kiem tra y co ke voi x khong */
int adjacent (Graph* G, int x, int y) {
	int e;
	for (e = 1; e <= G->m; e++)
		if (x != y && G->A[x][e] == 1 && G->A[y][e] == 1)
			return 1;
	return 0;
}

/* Tinh bac cua dinh x: deg(x) */
int degree (Graph* G, int x) {
	int e, deg = 0;
	for (e = 1; e <= G->m; e++)
		if (G->A[x][e] == 1)
			deg++;
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

/*****************************************************************************************/