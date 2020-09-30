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
		if(L[i]<=R[j]) a[k++] = L[i++];
		else a[k++] = R[j++];
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

int main(){
	freopen("sapxep.inp", "r", stdin);
	int n; scanf("%d", &n);
	int arr[n];
	int i, j;
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	for(i=0;i<n;i++)
		printf("%d ", arr[i]);
	printf("\n");
	MergeSort(arr, 0, n-1);
	for(i=0;i<n;i++)
		printf("%d ", arr[i]);
	return 0;
}
