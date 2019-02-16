#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[101][101];
bool check[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
typedef struct {
	int x;
	int y;
}Pos;

bool isValid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}
void bfs() {
	queue<pair<Pos, int>> q;
	Pos start;
	start.x = 0;
	start.y = 0;
	q.push(make_pair(start, 0));
	check[start.x][start.y] = true;

	while (!q.empty()) {
		int curX = q.front().first.x;
		int curY = q.front().first.y;
		int dist = q.front().second;
		q.pop();

		if (curX == n - 1 && curY == m - 1) {
			cout << dist + 1 << endl;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int newX = curX + dx[i];
			int newY = curY + dy[i];

			if (isValid(newX, newY)) {
				if (map[newX][newY] == 1 && check[newX][newY] == false) {
					check[newX][newY] = true;
					Pos pos;
					pos.x = newX;
					pos.y = newY;
					q.push(make_pair(pos, dist + 1));
				}
			}
		}
	}
}
int main(void) {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	bfs();
	return 0;
}