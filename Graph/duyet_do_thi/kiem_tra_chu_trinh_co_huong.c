#include <stdio.h>
#define MAX_ELEMENTS 100
#define MAX_VERTICES 100
#define white 0 // Chua duoc duyet
#define black 1	// Duyet xong
#define gray 2	// Dang duyet

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

int color[MAX_VERTICES];
int cycle;

/* Duyet do thi bat dau tu dinh x */
void dfs (Graph* G, int x) {
	color[x] = gray;
	int j;
	List list = neighbors(G, x);
	for (j = 1; j <= list.size; j++) {
		int y = element_at(&list, j);
		if (color[y] == gray) {
			cycle = 1; /* Ton tai chu trinh */
			return;
		}
		if (color[y] == white)
			dfs(G, y);
	}
	color[x] = black;
}

/* Kiem tra toan bo do thi */
int contains_cycle (Graph* G) {
	int j;
	for (j = 1; j <= G->n; j++)
		color[j] = white;
	cycle = 0;
	for (j = 1; j <= G->n; j++)
		if (color[j] == white)
			dfs(G, j);
	return cycle;
}

/****************************************************************************************/
int main() {
	Graph G;
	int n, m, i;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (i = 1; i <= m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		add_edges(&G, a, b);
	}
	if (contains_cycle(&G) == 0)
		printf("YES");
	else printf("NO");
	return 0;
}