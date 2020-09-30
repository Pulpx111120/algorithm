#include <stdio.h>

long long C(long long i, long long j){
	if(i==0 || i==j) return 1;
	else
		return C(i-1, j-1) + C(i, j-1);
//		return C(i, j-1)*(i-j+1)/j;
}

int main(){
	long long n; scanf("%lld", &n);
	long long i, j;
	for(i=0;i<=n;i++){
		for(j=0;j<=i;j++)
			printf("%lld ", C(j, i));
		printf("\n");
	}
		
	return 0;
}
