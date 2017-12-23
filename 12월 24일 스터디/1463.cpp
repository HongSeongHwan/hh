#include<stdio.h>
#include<stdlib.h>
int main() {
	int N;
	int temp;
	int counter = 0;
	int v2, v4, v3, vm;
	//int d[10001];
	int *d;
	scanf("%d", &N);
	temp = N;

	d = (int *)malloc(sizeof(int)*(N + 10));

	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	d[4] = 2;

	for (int i = 4; i <= N + 1; i++) {
		if (i % 2 == 0 && i % 3 == 0) {
			//printf("a1 \n");
			v2 = d[i / 2];
			v3 = d[i / 3];
			vm = d[i - 1];
			if (v2 < v3 && v2 < vm) {
				d[i] = v2 + 1;
			}
			else if (v3 < vm) {
				d[i] = v3 + 1;
			}
			else {
				d[i] = vm + 1;
			}
		}
		else if (i % 2 == 0) {
			//	printf("a2 \n");
			v2 = d[i / 2];
			vm = d[i - 1];
			if (v2 < vm) {
				d[i] = v2 + 1;
			}
			else {
				d[i] = vm + 1;
			}
		}
		else if (i % 3 == 0) {
			//	printf("a3 \n");
			v3 = d[i / 3];
			vm = d[i - 1];
			if (v3 < vm) {
				d[i] = v3 + 1;
			}
			else {
				d[i] = vm + 1;
			}
		}
		else {
			//printf("a4 \n");
			d[i] = d[i - 1] + 1;
		}
		//	counter++;

	}
	printf("%d", d[temp]);
	//printf("aa");
	free(d);

}