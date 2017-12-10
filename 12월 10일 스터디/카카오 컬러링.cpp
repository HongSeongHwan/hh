#include <vector>
#include<list>
#include <utility>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
int check[100][100];
queue<int> xque;
queue<int> yque;
int a[4] = { 0,1,0,-1 };
int b[4] = { 1,0,-1,0 };
int search(int x, int y, vector<vector<int>> picture, int m, int n) {
	int sum = 0;
	int pic = picture[x][y];
	check[x][y] = 1;
	xque.push(x);
	yque.push(y);
	while (xque.size() > 0) {
		int x = xque.front(); xque.pop();
		int y = yque.front(); yque.pop();
		sum++;
		for (int i = 0; i < 4; i++) {
			int nx = x + a[i];
			int ny = y + b[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && check[nx][ny] == 0 && picture[nx][ny] == pic) {
				check[nx][ny] = 1;
				xque.push(nx);
				yque.push(ny);
			}
		}
	}
	return sum;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			check[i][j] = 0;
		}
	}
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			if (picture[i][j] == 0) {
			}
			else if (check[i][j] == 0) {
				int temp;
				temp = search(i, j, picture, m, n);
				answer[0]++;
				if (temp > answer[1]) {
					answer[1] = temp;
				}
			}
		}
	}
	return answer;
}