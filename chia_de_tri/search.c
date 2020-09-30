#include <stdio.h>

int binarySearch(int a[], int l, int r, int x){
	if(r>=l){
		int m = l+(r-l)/2;
		if(a[m]==x) return 1;
		if(a[m]>x)
			return binarySearch(a, l, m-1, x);
		else return binarySearch(a, m+1, r, x);
	}
	return 0;
}

int search(int a[], int l, int h, int x){
	if(l==h){
		if(x==a[l]) return 1;
		else return 0;
	}
	else{
		int m = (l+h)/2;
		if(x==a[m]) return 1;
		else if(x<a[m])
			return search(a, m+1, h, x);
		else
			return search(a, l, m-1, x);
	}
}

//void Merge(int a[], int l, int m, int r){
//	int i, j, k;
//	int n1 = m-l+1;
//	int n2 = r-m;
//	int L[n1], R[n2];
//	for(i=0;i<n1;i++)
//		L[i] = a[l+i];
//	for(j=0;j<n2;j++)
//		R[j] = a[m+1+j];
//	
//	i=0;
//	j=0;
//	k=l;
//	
//	while(i<n1 && j<n2){
//		if(L[i]<=R[j]) a[k++] = L[i++];
//		else a[k++] = R[j++];
//	}
//	
//	for(;i<n1;)
//		a[k++] = L[i++];
//	for(;j<n2;)
//		a[k++] = R[j++];
//}
//
//void MergeSort(int a[], int l, int r){
//	if(l<r){
//		int m = l+(r-l)/2;
//		MergeSort(a, l, m);
//		MergeSort(a, m+1, r);
//		Merge(a, l, m, r);
//	}
//}
//
//void search(const char* fName){
//	freopen(fName, "r", stdin);
//	int n, q; scanf("%d%d", &n, &q);
//	int arr[n], brr[q];
//	int i;
//	for(i=0;i<n;i++)
//		scanf("%d", &arr[i]);
//	for(i=0;i<q;i++)
//		scanf("%d", &brr[i]);
//	MergeSort(arr, 0, n-1);
//	for(i=0;i<q;i++){
//		if(binarySearch(arr, 0, n-1, brr[i]) != -1)
//			printf("YES\n");
//		else printf("NO\n");
//	}
//}

int main(){
//	int A[] = {1, 3, 6, 7, 10};
	int A[] = {10, 7, 6, 3, 1};
	int n = sizeof(A)/sizeof(int);
//	printf("%d", binarySearch(A, 0, n-1, 7));
	printf("%d", search(A, 0, n-1, 103));
	return 0;
}
