#include <iostream>

using namespace std;

int dp[1000001];



int main(void) {
	
	int testcase;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	cin >> testcase;
	int n;
	while (testcase--) {
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}