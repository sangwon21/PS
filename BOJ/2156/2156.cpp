#include <iostream>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

long long dp[10001][3];
long long wine[10001];

int main(void) {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}
	dp[0][0] = 0;
	dp[0][1] = wine[0];
	

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + wine[i];
		dp[i][2] = dp[i - 1][1] + wine[i];
	}

	cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;
	return 0;
}