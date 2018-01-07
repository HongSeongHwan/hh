#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
	int c;
	int p;
	int p2;
	int n;
	cin >> n;
	c = 2;
	p = 2;
	p2 = 1;
	for (int i = 3; i <= n; i++) {
		c = p + p2;
		c = c % 10007;
		p2 = p;
		p = c;
	}
	if (n == 1) {
		printf("1");
		return 0;
	}
	printf("%d", c  );
}
