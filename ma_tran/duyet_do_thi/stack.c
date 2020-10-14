#include <stdio.h>
#include <E:/LTDT/TH2/duyet_do_thi/duyet_chieu_sau_stack.c>

int main() {
	freopen("stack.inp", "r", stdin);
	Graph G;
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		add_edge(&G, a, b);
	}
//	for (i = 1; i <= m; i++)
//		printf("deg(%d) = %d\n", i, degree(&G, i));
//	for (i = 1; i <= n; i++) {
//		List L = neighbors(&G, i);
//		printf("Cac dinh ke cua %d: [ ", i);
//		for (j = 1; j <= L.size; j++)
//			printf("%d ", element_at(&L, j));
//		printf("]\n");
//	}
	depth_first_search(&G);
	return 0;
}
