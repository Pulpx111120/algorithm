#include <stdio.h>
#include <E:/LTDT/TH1/ma_tran_dinh_dinh/Graph.c>

int main() {
	Graph G;
	freopen("test2.txt", "r", stdin);
	int n, i, v, a, b; 
	scanf("%d%d", &n, &v);
	init_graph(&G, n);
	for (i = 0; i < v; i++) {
		scanf("%d%d", &a, &b);
		add_edges(&G, a, b);
	}
	for (i = 1; i <= n; i++)
		printf("deg(%d) = %d\n", i, degrees(&G, i));
	return 0;
}
