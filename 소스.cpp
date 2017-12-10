#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 48000
int main() {
	int i;
	for (i = 1; i <= N; i++) {
		char target[200] = "refimg";
		char ch1[200];
		char out[200] = "sat_train_";
		int len, j;
		itoa(i, ch1, 10);
		len = strlen(ch1);
		for (j = 0; j < (5 - len); j++) {
			strcat(out, "0");
		}
		strcat(out, ch1);
		strcat(target, ch1);

		strcat(out, ".png");
		strcat(target, ".png");

		if (i % 1000 == 0) {
			printf("%d \n", i);
		}
		rename(target, out);
	}
}
