#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int papers[2200][2200];
int cnt[3];

bool isValid(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (papers[x][y] != papers[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void solve(int x, int y, int n) {
	if (isValid(x, y, n)) {
		cnt[papers[x][y] + 1] += 1;
		return;
	}
	int m = n / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(x + i * m, y + j * m, m);
		}
	}
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &papers[i][j]);
		}
	}

	solve(0, 0, n);

	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << endl;
	}
	return 0;
}