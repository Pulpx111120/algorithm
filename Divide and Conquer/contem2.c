#include <stdio.h>
#include <malloc.h>

long binarySearch(long *T, long key, long l, long h){
	if(h>=l){
        long m = l+(h-l)/2;
        if(T[m]==key) return m;
        if(T[m]>key && T[m-1]<key)
        	return m+1;
        else{
        	if(T[m]<key)
                return binarySearch(T, key, m+1, h);
            else
                return binarySearch(T, key, l, m-1);
		}
	}
    return 1;
}

int main(){
	freopen("contem.inp", "r", stdin);
	long n, q, *A, *T, *x;
	scanf("%ld  %ld", &n, &q);
	A = (long*)malloc(n*sizeof(long));
	T = (long*)malloc(n*sizeof(long));
	x = (long*)malloc(n*sizeof(long));
	int i;
	for(i=0;i<n;i++)
		scanf("%ld", &A[i]);
	T[0] = A[0];
	for(i=1;i<=n;i++)
		T[i] = T[i-1]+A[i];
	for(i=0;i<q;i++)
		scanf("%ld", &x[i]);
	for(i=0;i<q;i++)
		printf("%ld \n", binarySearch(T, x[i], 0, n-1));
	return 0;
}
