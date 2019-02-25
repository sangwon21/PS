#include <iostream>
#include <queue>

using namespace std;

// m : °¡·Î Ä­ ¼ö, n : ¼¼·Î Ä­ ¼ö
int m, n;
int map[1001][1001];
int check[1001][1001];
int maxNum = 0;

queue<pair<int, int>> q;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool isValid(int y, int x) {
	return 0 <= x && x < m && 0 <= y && y < n;
}
void bfs() {
	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (isValid(nextY, nextX)) {
				if (map[nextY][nextX] == 0 && check[nextY][nextX] == 0) {
					check[nextY][nextX] = check[curY][curX] + 1;
					map[nextY][nextX] = 1;
					q.push(make_pair(nextY, nextX));
				}
			}
		}
	}
}

bool isBFSValid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
				return false;
			if (check[i][j] > maxNum)
				maxNum = check[i][j];
		}
	}
	return true;
}

int main(void) {
	
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				check[i][j] = 1;
			}
		}
	}

	bfs();
	bool judge = isBFSValid();

	if (judge)
		cout << maxNum - 1 << endl;
	else
		cout << -1 << endl;
	return 0;
}