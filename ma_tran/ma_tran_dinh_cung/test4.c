#include <stdio.h>
#include <E:/LTDT/TH1/ma_tran_dinh_cung/Graph.c>

int main(int argc, char* argv[]) {
	Graph G;
	int n, m, e, u, v;
	if (argc < 2) {
		printf("Hay go: %s <ten-file>\n", argv[0]);
		return 1;
	}
	
	FILE* file = fopen(argv[1], "r");
	fscanf(file, "%d%d", &n, &m);
	init_graph(&G, n, m);
	for (e = 1; e <= m; e++) {
		fscanf(file, "%d%d", &u, &v);
		add_edge(&G, e, u, v);
	}
	
	for (v = 1; v <=n; v++)
		printf("def(%d) = %d\n", v, degree(&G, v));
	return 0;
}
