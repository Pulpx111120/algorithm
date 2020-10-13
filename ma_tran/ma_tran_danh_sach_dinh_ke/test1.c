#include <stdio.h>

int main() {
	freopen("input.inp", "r", stdin);
	Graph G;
	int n, m, i;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		add_edge(&G, a, b);
	}
	for (i = 1; i <= n; i++)
		printf("deg(%d) = %d\n", i, degree(&G, i));
	return 0;
}