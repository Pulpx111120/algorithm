#include <stdio.h>

int main() {
	Graph G;
	int n = 4, i;
	init_graph(&G, n);
	add_edges(&G, 1, 2);
	add_edges(&G, 1, 3);
	add_edges(&G, 1, 3);
	add_edges(&G, 1, 4);
	add_edges(&G, 3, 4);
	for (i = 1; i <= n; i++)
		printf("deg(%d) = %d\n", i, degrees(&G, i));
	return 0;
}