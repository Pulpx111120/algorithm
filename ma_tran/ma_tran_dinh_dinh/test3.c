#include <stdio.h>
#include <E:/LTDT/TH1/ma_tran_dinh_dinh/Graph.c>

int main() {
	Graph G;
	int n = 4, i, j;
	init_graph(&G, n);
	add_edges(&G, 1, 2);
	add_edges(&G, 1, 3);
	add_edges(&G, 1, 4);
	add_edges(&G, 3, 4);
	add_edges(&G, 1, 3);
	for (i = 1; i <= n; i++) {
		List L = neighbors(&G, i);
		printf("Cac dinh ke cua %d: [ ", i);
		for (j = 1; j <= L.size; j++)
			printf("%d ", element_at(&L, j));
		printf("]\n");
	}
	return 0;
}
