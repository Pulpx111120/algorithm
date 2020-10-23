#include <stdio.h>

long modu(int a, int n, int p){
	if(n==0) return 1;
	long tmp = modu(a, n/2, p);
	if(n%2==0) 
		return (tmp*tmp)%p;
	return ((tmp*tmp)%p*a)%p;
}

int main(){
	freopen("modulo.inp", "r", stdin);
	int a, p; scanf("%d%d", &a, &p);
	printf("%ld", modu(a, p-2, p));
	return 0;
}
