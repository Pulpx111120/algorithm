#include <stdio.h>

int main() {
	Graph G;
	int n = 7, m = 9, v;
	init_graph(&G, n, m);
	add_edge(&G, 1, 1, 2);
	add_edge(&G, 2, 1, 3);
	add_edge(&G, 3, 1, 3);
	add_edge(&G, 4, 3, 6);
	add_edge(&G, 5, 1, 4);
	add_edge(&G, 6, 3, 4);
	add_edge(&G, 7, 5, 6);
	add_edge(&G, 8, 5, 6);
	add_edge(&G, 9, 4, 5);
	
	for (v = 1; v <= n; v++)
		printf("deg(%d) = %d\n", v, degree(&G, v));
	return 0;
}