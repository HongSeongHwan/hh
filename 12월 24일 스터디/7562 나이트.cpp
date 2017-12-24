#include<stdio.h>
#include<iostream>
#include<list>
#include<utility>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


int xp[8] = { 1,1, 2,2  ,-1,-1,-2,-2};
int yp[8] = { 2,-2,1,-1 , 2,-2,1,-1};

int map[400][400];

int main() {
	int num;
	cin >> num;
	for (int testcase = 0; testcase < num; testcase++) {
		queue<int> xq;
		queue<int> yq;
		queue<int> countq;
			int n;
			cin >> n;
			int check[400][400];
			int x, y, px, py;
			for (int i = 0; i < 400; i++) {
				for (int j = 0; j < 400; j++) {
					check[i][j] = 0;
				}
			}
			cin >> x >> y >> px >> py;
			//	cout << "s";
			check[x][y] = 1;
			xq.push(x);
			yq.push(y);
			countq.push(0);
			while (xq.size() > 0) {
				int c;
				x = xq.front(); xq.pop();
				y = yq.front(); yq.pop();
				c = countq.front(); countq.pop();
				if (x == px && y == py) {
					printf("%d\n", c);
					break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + xp[i];
					int ny = y + yp[i];
					if (nx >= 0 && ny >= 0 && nx < n && ny < n && check[nx][ny] == 0) {
						check[nx][ny] = 1;
						xq.push(nx);
						yq.push(ny);
						countq.push(c + 1);
					}
				}
			}
	}
}
