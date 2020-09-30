#include <stdio.h>

//Dung de quy
int BinarySearch_dq(int a[], int x, int left, int right){
	if(left>right) return -1;	//ko tim thay
	int mid=(left+right)/2;		//tinh trung diem
	if(x==a[mid]) return mid;	//tra ve vi tri tim thay
	if(x<a[mid]) return BinarySearch_dq(a, x, left, mid-1);
	else return BinarySearch_dq(a, x, mid+1, right);
}

int BinarySearch(int a[], int x, int n){
	return BinarySearch_dq(a, x, 0, n-1);
}

//Khu de quy
int BinarySearch2(int a[], int x, int n){
	int left, right, mid;
	left=0;
	right=n-1;
	while(left<=right){
		mid=(left+right)/2;
		if(x==a[mid]) return mid;
		else if(x<a[mid]) right=mid-1;
		else left=mid+1;
	}
	return -1;
}

int main(){
	int a[]={1, 3, 4, 5, 7, 9, 10, 15};
	printf("%d\n", BinarySearch(a, 9, 8));
	printf("%d\n", BinarySearch2(a, 9, 8));
	printf("%d\n", BinarySearch(a, 0, 8));
	printf("%d", BinarySearch2(a, 0, 8));
	return 0;
}