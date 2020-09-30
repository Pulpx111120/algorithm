#include<stdio.h>

void atm(int n){
	int A[6]={500000, 200000, 100000, 50000, 20000, 10000};
	int X[6]={0, 0, 0, 0, 0, 0};
	int i=0;
	if(n%10000==0)
		while(n>0){
			X[i]=n/A[i];
			n%=A[i];
			i++;
		}
	else printf("KHONG RUT DUOC");
	for(i=0;i<6;i++){
		if(X[i]!=0)
			printf("%d VND: %d\n", A[i], X[i]);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	atm(n);
	return 0;
}
