#include <stdio.h>
#define MAX 100

//Dinh nghia cau truc luu tru thong tin cua 1 mon do
typedef struct{
	int w;		//trong luong
	int v;		//gia tri
	int num;	//so luong hien co
}MONDO;

//Sap xep danh sach do vat theo tieu chi
//a. Sap tang dan theo trong luong
void sort_1(MONDO a[], int n){
	int i, j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i].w > a[j].w){
				MONDO tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

//b. Sap giam dan theo gia tri
void sort_2(MONDO a[], int n){
	int i, j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i].v < a[j].v){
				MONDO tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

//c. Sap giam dan theo don gia=gia tri/trong luong
void sort_3(MONDO a[], int n){
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

//Lua chon cac do vat cho vao tui theo phuong phap tham lam
//Ham tra ve tong gia tri cua nhung mon do trong tui
//w: la suc chua toi da cua tui
//soluong: la mang 1 chieu luu so luong cua moi loai do vat duoc chon
float greedy(MONDO a[], int n, int w){
	int i=0, j=0, count=0;
	int soluong[n];
	sort_3(a, n);
	while(i<n){
		if(w>=a[i].w){
			w -= a[i].w;
			count++;
		}
		else{
			soluong[i++]=count;
			count=0;
		}
	}
	float gia_tien=0.0;
	for(;j<n;j++)
		gia_tien = gia_tien + (soluong[j] * a[j].v);
	return gia_tien;
}

//int greedy(MONDO a[], int n, int w){
//	//b1. sap xep
//	sort_3(a, n);
//	//b2. duyet qua tung loai do vat va lay so luong co the lay
//	int i;
//	int tong_gia_tri = 0;
//	int soluong[n];
//	for(i=0;i<n;i++){
//		if(w>0){
//			soluong[i] = w / a[i].w;
//			w -= soluong[i] * a[i].w;
//			tong_gia_tri += soluong[i] * a[i].v;
//		}
//		else break;
//	}
//	return tong_gia_tri;
//}

int main(){
	MONDO a[MAX];
	int n, i, w;
	freopen("tui_xach.txt", "r", stdin);
	scanf("%d", &n);
	scanf("%d", &w);
	for(i=0;i<n;i++)
		scanf("%d", &a[i].w);
	for(i=0;i<n;i++)
		scanf("%d", &a[i].v);
//	for(i=0;i<n;i++)
//		printf("(%d, %d)\n", a[i].w, a[i].v);
//	sort_3(a, n);
//	for(i=0;i<n;i++)
//		printf("(%d, %d)\n", a[i].w, a[i].v);
	printf("%f ", greedy(a, n, w));
	return 0;
}
