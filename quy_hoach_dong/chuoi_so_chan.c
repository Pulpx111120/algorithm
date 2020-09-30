#include <stdio.h>
#include <string.h>
#define MAX 10000

int isF(int a){
	return (a%2==0) ? 1 : 0;
}

//int count(int n, char c[], int A[]){
//	if(n==strlen(c)-1){
//		if(isF(c[n])){
//			A[n] = 1;
//			return A[n];
//		}
//		else{
//			A[n] = 0;
//			return A[n];
//		}
//	}
//	else{
//		if(isF(c[n])){
//			A[n] = 1 + count(n+1, c, A);
//			return A[n];
//		}
//		else{
//			A[n] = count(n+1, c, A);
//			return A[n];
//		}
//	}
//}

int main(){
	freopen("chuoi_so_chan.inp", "r", stdin);
	char str[MAX];
	gets(str);
	int n = strlen(str);
	int A[n];
	int i, j;
	for(i=0;i<n;i++){
		int count = 0;
		for(j=i;j<n;j++){
			if(isF(str[j]))
				count++;
		}
		A[i] = count;
	}
//	count(0, str, A);
	for(i=0;i<n;i++)
		printf("%d ", A[i]);
	return 0;
}
