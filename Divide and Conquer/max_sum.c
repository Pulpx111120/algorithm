#include <stdio.h>

int max(int a, int b){
	return (a>b)?a:b;
}

int maxleft(int A[], int i, int j){
	int maxsum = 0;
	int sum = 0;
	int k;
	for(k=j;k>=i;k--){
		sum+=A[k];
		maxsum=max(sum, maxsum);
	}
	return maxsum;
}

int maxright(int A[], int i, int j){
	int maxsum=0;
	int sum=0;
	int k;
	for(k=i;k<=j;k++){
		sum+=A[k];
		maxsum=max(sum, maxsum);
	}
	return maxsum;
}

int maxsub(int A[], int i, int j){
	if(i==j) return A[i];
	int m=(i+j)/2;
	int wL=maxsub(A, i, m);
	int wR=maxsub(A, m+1, j);
	int wM=maxleft(A, i, m)+maxright(A, m+1, j);
	return max(max(wL, wR), wM);
}

int max_sum(int A[], int n){
	return maxsub(A, 1, n);
}

int main(){
	freopen("max_sum.inp", "r", stdin);
	int n; scanf("%d", &n);
	int A[1000];
	int i;
	for(i=0;i<1000;i++)
		scanf("%d", &A[i]);
	printf("%d", max_sum(A, n));
}
