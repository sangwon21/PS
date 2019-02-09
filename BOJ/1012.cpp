#include <iostream>

using namespace std;

int farm[51][51];
bool check[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt = 0;
// 배추 개수
int k;
// m : 가로, n : 세로
int m, n;
int testcase;

void dfs(int y, int x, int color) {
	if (check[y][x] == false)
		return;

	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];
		
		if (0 <= newY && newY < n && 0 <= newX && newX < m) {
			if (check[newY][newX] == false && farm[newY][newX] == 1) {
				check[newY][newX] = true;
				farm[newY][newX] = color;
				dfs(newY, newX, color);
			}
		}
	}
}
int main() {
	
	cin >> testcase;

	while (testcase--) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			farm[b][a] = 1;
		}
		int color = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (farm[i][j] == 1 && check[i][j] == false) {
					check[i][j] = true;
					dfs(i, j, ++color);
				}
			}
		}
		printf("%d\n", color - 1);
		// farm, check, cnt초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				farm[i][j] = check[i][j] = 0;
			}
		}
		cnt = 0;
	}
	return 0;
}