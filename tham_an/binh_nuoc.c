#include <stdio.h>

void Merge(int a[], int l, int m, int r){
	int i, j, k;
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1], R[n2];
	for(i=0;i<n1;i++)
		L[i] = a[l+i];
	for(j=0;j<n2;j++)
		R[j] = a[m+1+j];
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]) a[k++]=L[i++];
		else a[k++]=R[j++];
	}
	for(;i<n1;)
		a[k++] = L[i++];
	for(;j<n2;)
		a[k++] = R[j++];
}

void MergeSort(int a[], int l, int r){
	if(l<r){
		int m = l+(r-l)/2;
		MergeSort(a, l, m);
		MergeSort(a, m+1, r);
		Merge(a, l, m, r);
	}
}

void solve(const char* fName){
	freopen(fName,"r", stdin);
	int i, j;
	int T; scanf("%d", &T);
	int N, X;
	for(i=0;i<T;i++){
		scanf("%d%d", &N, &X);
		int arr[N];
		for(j=0;j<N;j++)
			scanf("%d", &arr[j]);
		MergeSort(arr, 0, N-1);
		int count = 0;
		int k = 0;
/*
10>2 10-2=8 count = 1
8>3 8-3=5 count = 2
5>4 5-4=1 count = 3
1<5 break
*/
		for(j=0;j<N;j++){
			if(X>=arr[j]){
				X -= arr[j];
				count++;	
			}
			else break;
		}
		printf("%d\n", count);
	}
}

int main(){
	solve("binh_nuoc.inp");
	return 0;
}
