#include <stdio.h>
#include <E:/LTDT/TH2/duyet_do_thi/duyet_theo_de_quy.c>

int main() {
	freopen("de_quy.inp", "r", stdin);
	Graph G;
	int n, m, i;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		add_edge(&G, a, b);
	}
//	depth_first_search(&G);
	if (count_connected_components(&G) == 1)
		printf("YES");
	else printf("NO");
	return 0;
}
