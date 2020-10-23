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

/* Mot so bien ho tro */
int color[MAX_VERTICES];
int fail;

/* To mau dinh bang phuong phap de quy */
void colorize (Graph* G, int x, int c) {
	/* Neu dinh x da chua co mau => to no */
	if (color[x] == -1) {
		color[x] = c;
		/* Lay cac dinh ke va to mau cac dinh ke bang mau nguoc voi c */
		List list = neighbors(G, x);
		int j;
		for (j = 1; j <= list.size; j++) {
			int y = element_at(&list, j);
			colorize(G, y, !c);
		}
	} else /* x da co mau */
		if (color[x] != c) /* 1 dinh bi to 2 mau khac nhau */
			fail = 1; /* that bai */
}

/* Kiem tra do thi co la do thi phan doi */
int is_bigraph (Graph* G) {
	/* Khoi tao color, chua dinh nao co mau */
	int j;
	for (j = 1; j <= G->n; j++)
		color[j] = -1;
	fail = 0;
	colorize(G, 1, 0); /* To mau dinh 1 bang mau den */
	/* Neu khong that bai, G la bigraph */
	return !fail;
}

void tmp (Graph* G) {
	int i, j, k, v;
	int mark[MAX_VERTICES];
	int ver[MAX_VERTICES];
	for (j = 1; j <= G->n; j++) {
		mark[j] = 0;
		ver[j] = 0;
	}
	for (i = 1; i <= G->n; i++) {
		List L = neighbors(G, i);		
		for (j = 1; j <= L.size; j++) {
			int y = element_at(&L, j);
			for (k = 1; k <= G->n; k++) {
				if (y == k) {
					mark[k] = 1;
					break;
				}
			}
		}
		for (v = 1; v <= G->n; v++) {
			if (mark[v] == 0 && ver[v] == 0) {
				printf("%d ", v);
				ver[v] = 1;
			}
			else mark[v] = 0;
			
		}
		printf("\n");
	}
}

/****************************************************************************************/
int main() {
	Graph G;
	int n, m, i;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		add_edge(&G, a, b);
	}
	if (is_bigraph(&G))
		tmp(&G);
	else printf("IMPOSSIBLE");
	return 0;
}