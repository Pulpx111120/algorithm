#include <stdio.h>

int main() {
	freopen("input.inp", "r", stdin);
	Graph G;
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		add_edge(&G, a, b);
	}
//	for (i = 1; i <= G.n; i++) {
//		printf("Cac dinh ke cua %d: [ ", i);
//		for (j = 0; j < G.adj[i].size; j++)
//			printf("%d ", G.adj[i].data[j]);
//		printf("]\n");
//	}
	for (i = 1; i <= n; i++) {
		List L = neighbors(&G, i);
		printf("Cac dinh ke cua %d: [ ", i);
		for (j = 1; j <= L.size; j++)
			printf("%d ", element_at(&L, j));
		printf("]\n");
	}
	return 0;
}