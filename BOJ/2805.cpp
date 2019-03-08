#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

long long N, M;
long long trees[1000000];
long long Max = 0;

bool check(long long mid) {
	long long result = 0;

	for (int i = 0; i < N; i++) {
		if (trees[i] < mid) continue;
		result += (trees[i] - mid);
	}

	return result >= M;
}

int main(void) {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &trees[i]);
		if (Max < trees[i])
			Max = trees[i];
	}
	long long left = 1, right = Max;
	long long ans = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;

		if (check(mid)) {
			if (ans < mid) {
				ans = mid;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}

	cout << ans << endl;
	return 0;
}