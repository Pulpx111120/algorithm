#include<stdio.h>
#include<string.h>
#include<malloc.h>

int count(int n, char c[], int A[]){
	if(n==(int)strlen(c)-1)
		if(c[n]%2==0){
			A[n]=1;
			return A[n];
		}
		else{
			A[n]=0;
			return A[n];
		}
	else
		if(c[n]%2==0){
			A[n]=1+count(n+1, c, A);
			return A[n];
		}
		else{
			A[n]=count(n+1, c, A);
			return A[n];
		}
}

int main(){
	char c[10000];
	scanf("%s", c);
	int A[strlen(c)];
	count(0, c, A);
	for(int i=0;i<(int)strlen(c);i++){
		printf("%d ", A[i]);
	}
	return 0;
}
