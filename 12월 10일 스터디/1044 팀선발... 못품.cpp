#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int sumbit(int n, long long int num) {
	int sum=0;
	for (long long int i = 0; i < n; i++) {
		if (num & 0x01) {
			sum++;
		}
		num = num >> 1;
	}
	return sum;
}
void print_info(int num, int team, int n) {
	printf("num %d \n", num);
	int x[100];
	for (int i = 0; i < n; i++) {
		if (team & 0x01) {
			x[n - i] = 1;
		}
		else {
			x[n - i] = 2;
		}
		team = team >> 1;
	}

	for (int i = 1; i <= n; i++) {
		if (x[i] == 1)
			printf("1 ");
		else
			printf("2 ");
	}
	printf("\n\n");
}

int main() {
	long long int n;
	long long int iter;
	int a[36];
	int b[36];
	long long int half;
	int out;
	long long int min=9999999;
	long long int pos;
	out = 0;
	scanf("%lld", &n);
	min = pow(2, 37) - 1;
	//printf("ll%d", min);
	half = n / 2;
	iter = pow(2,n);
//	printf("iter %d\n", iter);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);

	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	for (long long int i = 0; i < iter; i++) {
		out = 0;
		//
		int check = sumbit(n,i);
		
		if (check != half) {
		//..	printf("!! %d \n", check);
			continue;
		}
		//.//	printf("?? %d \n", check);
		long long int temp = i;
		//////////////////////////////////////////////////////////////////////////////////////
		for (int j = 0; j < n; j++) {
			if (temp & 0x01) {
				out +=a[(n-1)-j];
			}
			temp = temp >> 1;
		}
		temp = i;
		for (int j = 0; j < n; j++) {
			if (!(temp & 0x01)) {
				out -= b[(n - 1) - j];
			}
			temp = temp >> 1;
		}
		//////////////////////////////////////////////////////////////////////////////////////
		//print_info(out, i, n);
		if (out < 0) {
			out = out*-1;
		}
		if (out <= min) {
		//	print_info(out, i, n);
			min = out;
			pos = i;
		//	print_info(out, i, n);
		//	printf("i %d \n", i);
		}
		//print_info(out, i, n);
	}
	int x[100];
	for (int i = 0; i < n; i++) {
		if (pos & 0x01) {
			x[n - i] = 1;
		}
		else {
			x[n - i] = 2;
		}
		pos = pos >> 1;
	}
	for (int i = 1; i <= n; i++) {
		if (x[i] == 1)
			printf("1 ");
		else
			printf("2 ");
	}
}