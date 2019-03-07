#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int K, N;
long long lines[10000];

bool check(long long mid) {
	int ans = 0;
	for (int i = 0; i < K; i++) {
		ans += (lines[i] / mid);
	}
	return ans >= N;
}

int main(void) {
	scanf("%d %d", &K, &N);
	long long Max = 0;
	for (int i = 0; i < K; i++) {
		scanf("%lld", &lines[i]);
		if (lines[i] > Max) {
			Max = lines[i];
		}
	}

	long long left = 1, right = Max;
	long long ans = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;

		if (check(mid)) {
			if(ans < mid){
				ans = mid;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	printf("%lld\n", ans);
	return 0;
}