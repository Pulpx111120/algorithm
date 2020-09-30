#include <stdio.h>

int main(){
	freopen("mon_do_choi.inp", "r", stdin);
	int n, m; scanf("%d%d", &n, &m);
	int arr[m];
	int i;
	int result = 0;
	for(i=0;i<m;i++)
		arr[i] = 0;
	for(i=0;i<n;i++){
		int result; scanf("%d", &result);
		int index; scanf("%d", &index);
		if(result>=arr[index-1])
			arr[index-1] = result;
	}
	for(i=0;i<m;i++)
		result += arr[i];
	printf("%d", result);
	return 0;
}
