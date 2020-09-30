#include <stdio.h>
#define MAX 100000

typedef struct{
	int w;		//trong luong
	int v;		//gia tri
}MONDO;

void sort(MONDO a[], int n){
	int i, j;
	float gia_tri[n];
	for(i=0;i<n;i++)
		gia_tri[i] = (float)a[i].v / a[i].w;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(gia_tri[i] < gia_tri[j]){
				MONDO tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

void greedy(MONDO a[], int n, int w){
	int i=0, j=0, count=0;
	float tong_tien=0.0;
	sort(a, n);
	for(;i<n;i++){
		if(w>=a[i].w){
			w -= a[i].w;
			tong_tien += (float)a[i].v;
		}
		else{
			tong_tien += ((float)w/a[i].w)*a[i].v;
			w -= w;
			break;
		}
	}
	printf("%.4f", tong_tien);
}

int main(){
	MONDO a[MAX];
	int n, i, int w;
	freopen("E:/PTTKTT/Input/Knapsack/knapsack04.inp", "r", stdin);
	scanf("%d", &n);
	scanf("%d", &w);
	for(i=0;i<n;i++)
		scanf("%d", &a[i].w);
	for(i=0;i<n;i++)
		scanf("%d", &a[i].v);
	greedy(a, n, w);
	return 0;
}
