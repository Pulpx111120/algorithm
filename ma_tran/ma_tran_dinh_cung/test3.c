#include <stdio.h>
#include <E:/LTDT/TH1/ma_tran_dinh_cung/Graph.c>

int main() {
	Graph G;
	freopen("test3.txt", "r", stdin);
	int n, m, i, v; scanf("%d%d", &n, &m);
	init_graph(&G, n, m);
	for (i = 1; i <= m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		add_edge(&G, i, a, b);
	}	
	for (v = 1; v <= n; v++)
		printf("deg(%d) = %d\n", v, degree(&G, v));
	return 0;
}
