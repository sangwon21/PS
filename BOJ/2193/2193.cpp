#include <iostream>

using namespace std;

long long dp[100][3];
int main(void) {
	
	int n;
	cin >> n;

	dp[2][0] = 0;
	dp[2][1] = 0;
	dp[2][2] = 1;

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	else if (n == 2) {
		cout << 1 << endl;
		return 0;
	}
	else {
		for (int i = 3; i <= n; i++) {
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
			dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
			dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
		}
	}

	long long sum = 0;
	sum += dp[n][0] + dp[n][1] + dp[n][2];

	cout << sum << endl;
	return 0;
}