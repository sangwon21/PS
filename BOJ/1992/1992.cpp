#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int quadTree[65][65];
int num;

bool isValid(int x,int y,int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (quadTree[x][y] != quadTree[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void solve(int x, int y, int n) {
	if (isValid(x, y, n)) {
		printf("%d", quadTree[x][y]);
		return;
	}
	else {
		int divN = n / 2;
		printf("(");
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				solve(x + i * divN, y + j * divN, divN);
			}
		}
		printf(")");
	}
}

int main(void) {
	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%1d", &quadTree[i][j]);
		}
	}

	solve(0, 0, num);
	return 0;
}