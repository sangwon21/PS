#include <iostream>
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;

int sticker[100001][2];
long long dp[100001][3];

long long comp(long long a,long long b) {
	if (a > b)
		return a;
	return b;
}

int main(void) {
	int testcase;
	cin >> testcase;

	while (testcase--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> sticker[i][0];
		}
		for (int i = 0; i < n; i++) {
			cin >> sticker[i][1];
		}
		dp[0][0] = sticker[0][0];
		dp[0][1] = sticker[0][1];
		dp[0][2] = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][0] = comp(dp[i - 1][1], dp[i - 1][2]) + sticker[i][0];
				
				dp[i][1] = comp(dp[i - 1][0], dp[i - 1][2]) + sticker[i][1];
			
				dp[i][2] = comp(comp(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);	
			}
		}
		long long ans = 0;

			ans = max(max(ans, dp[n -1][0]), max(dp[n - 1][1], dp[n - 1][2]));
		
		printf("%lld\n", ans);
	}

	return 0;
}