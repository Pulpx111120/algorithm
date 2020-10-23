#include <stdio.h>

int binarySearch_(int a[], int l, int r, int x){
	int m = (l+r)/2;
	while(l!=m && m!=r){
		if(a[m]>=x) r=m;
		else l=m;
		m = (l+r)/2;
	}
	int index;
	for(index=l;index<=r;index++)
		if(a[index]>=x) break;
	return index+1;
}

int main(){
	freopen("contem.inp", "r", stdin);
	int n, q; scanf("%d%d", &n, &q);
	int arr[n], brr[q], crr[n];
	int i, j, k;
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	for(i=0;i<q;i++)
		scanf("%d", &brr[i]);
	
	crr[0] = arr[0];
	for(i=1;i<n;i++)
		crr[i] = crr[i-1] + arr[i];
	
	for(i=0;i<q;i++)
		printf("%d\n", binarySearch_(crr, 0, n-1, brr[i]));
	
	return 0;
}
