#include <iostream>

using namespace std;

int r, c;

int power2(int k) {
	return (1 << k);
}

int solve(int x, int y, int n) {

	if (n == 1) {
		return 2 * x + y;
	}

	if (x < power2(n - 1)) {
		if (y < power2(n - 1)) {
			return solve(x, y, n - 1);
		}
		else {
			return solve(x, y - power2(n - 1), n - 1) + power2(2 * n - 2);
		}
	}
	else {
		if (y < power2(n - 1)) {
			return solve(x - power2(n - 1), y, n - 1) + power2(2 * n - 2) * 2;
		}
		else {
			return solve(x - power2(n - 1), y - power2(n - 1), n - 1) + power2(2 * n - 2) * 3;
		}
	}
}

int main(void) {

	int n;
	cin >> n >> r >> c;
	cout << solve(r, c, n);
	return 0;
}