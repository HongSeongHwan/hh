#include<stdio.h>
int main(){
	int a[100000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		a[1] = 1;
		a[2] = 2;
		a[3] = 4;

		for (int j = 4; j <= num; j++) {
			a[j] = a[j - 1] + a[j - 2] + a[j - 3];
		}
		printf("%d \n", a[num]);
	}
}