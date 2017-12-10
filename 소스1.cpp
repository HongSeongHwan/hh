#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int x[1000000][1000];
int main() {
	int coin[100];
	int coin_num[100];
	int money;
	int coin_num_iter;
	int i, j, k;
	scanf("%d", &money);
	scanf("%d", &coin_num_iter);
	for (i = 0; i < coin_num_iter; i++) {
		scanf("%d", coin + i);
	}
	for (i = 0; i < coin_num_iter; i++) {
		scanf("%d", coin_num + i);
	}	
}