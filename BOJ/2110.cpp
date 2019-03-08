#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

long long N, C;
long long houses[20001];
long long Max = 0;

long long check(long long mid) {
	long long wifis = 0;
	
	for (int i = 0; i < N; i++) {

	}

	return wifis >= C;
}
int main(void) {

	scanf("%lld %lld", &N, &C);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &houses[i]);
		if (houses[i] > Max) {
			Max = houses[i];
		}
	}

	long long left = 1;
	long long right = Max;
	long long ans = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;

		long long judge = check(mid);
		if (!check(mid)) {
			right = mid - 1;
		}
		else {
			if (ans < mid) {
				ans = mid;
			}
			left = mid + 1;
		}	
	}

	cout << ans << endl;
	return 0;
}