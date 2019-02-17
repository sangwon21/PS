#include <iostream>

using namespace std;

long long dp[101][10];

int main(void) {
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][1] % 1000000000;
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][8] % 1000000000;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}

	long long sum = 0;

	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
	}

	cout << sum % 1000000000 << endl;
	return 0;
}