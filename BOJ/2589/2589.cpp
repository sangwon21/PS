#include <iostream>
#include <queue>

using namespace std;

char map[51][51];
int check[51][51];

int row, column;
int maxNum = 0;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool isValid(int y, int x) {
	return 0 <= y && y < row && 0 <= x && x < column;
}

void bfs(int y, int x) {
	queue<pair<int, int>>q;
	q.push(make_pair(y, x));
	check[y][x] = 1;

	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		if (check[curY][curX] > maxNum)
			maxNum = check[curY][curX];
		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (isValid(nextY, nextX)) {
				if (map[nextY][nextX] == 'L' && check[nextY][nextX] == 0) {
					check[nextY][nextX] = check[curY][curX] + 1;
					q.push(make_pair(nextY, nextX));
				}
			}
		}
	}
}

void initCheck() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			check[i][j] = 0;
		}
	}
}

int main(void) {

	cin >> row >> column;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (map[i][j] == 'L') {
				bfs(i, j);
				initCheck();
			}
		}
	}

	cout << maxNum - 1 << endl;
	return 0;
}