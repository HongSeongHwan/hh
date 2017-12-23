#include<stdio.h>
#include<iostream>
#include<list>
#include<utility>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int check[40][40];
queue<int> xq;
queue<int> yq;
vector<int> va;
int n;
int xp[4] = { 0,1,0,-1 };
int yp[4] = { 1,0,-1,0 };
int map[100][100];
int search(int i, int j) {
	int out; int x = i; int y = j;
	int sum = 0;
	check[i][j] = 1;
	xq.push(x);
	yq.push(y);
	while (xq.size() > 0) {
		x = xq.front(); xq.pop();
		y = yq.front(); yq.pop();
		sum++;
		for (int i = 0; i < 4; i++) {
			int nx = x + xp[i];
			int ny = y + yp[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n && check[nx][ny] == 0 && map[nx][ny] == 1) {
				check[nx][ny] = 1;
				xq.push(nx);
				yq.push(ny);
			}
		}
	}
	out = sum;
	return out;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ch[25];
		cin >> ch;
		for (int j = 0; j < n; j++) {
			if (ch[j] == '0') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = 1;
			}
			check[i][j] = 0;
		}
	}
	//	cout << "s";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j<n; j++) {
			if (check[i][j] == 0 && map[i][j] == 1) {
				va.push_back(search(i, j));
			}
		}
	}
	sort(va.begin(), va.end());
	cout << va.size() << endl;
	for (int i = 0; i < va.size(); i++) {
		cout << va[i] << endl;
	}

}