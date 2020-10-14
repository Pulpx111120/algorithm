#include <stdio.h>
#include <E:/LTDT/TH2/duyet_do_thi/duyet_theo_chieu_rong_queue.c>

int main() {
	freopen("queue.inp", "r", stdin);
	Graph G;
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		add_edge(&G, a, b);
	}
	breath_first_search(&G);
	return 0;
}
