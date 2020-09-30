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

int main(){
	int a[]={8, 5, 4, 2, 6, 9, 1, 3};
	int n = sizeof(a)/sizeof(n);
	int i, j;
	for(i=0;i<n;i++)
		printf("%d ", a[i]);
	MergeSort(a, 0, n-1);
	printf("\n");
	for(j=0;j<n;j++)
		printf("%d ", a[j]);
	return 0;
}
