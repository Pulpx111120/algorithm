#include<stdio.h>

void print2PowerRecursion(int cur, int n){
	if(n==0) return;
	cur *= 2;
	printf("%d ", cur);
	print2PowerRecursion(cur, n-1);
}

void print2Power(int n){
	printf("1 ");
	print2PowerRecursion(1, n);
}

int main(){
	print2Power(5);
	return 0;
}
