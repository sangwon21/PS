#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int playgrounds[10000];
int N, M;


int main(void) {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &playgrounds[i]);
	}

	if (N <= M) {
		printf("%d\n", N);
		return 0;
	}
	long long left = 1, right = 2000000000LL * 1000000LL;

	while (left <= right) {

		long long mid = (left + right) / 2;

		long long begin, end;

		end = M;
		for (int i = 0; i < M; i++) {
			end += mid / playgrounds[i];
		}

		begin = end;

		for (int i = 0; i < M; i++) {
			if (mid % playgrounds[i] == 0) {
				begin -= 1;
			}
		}

		begin += 1;
		if (N < begin) {
			right = mid + 1;
		}
		else if (N > end) {
			left = mid - 1;
		}
		else {
			for (int i = 0; i < M; i++) {
				if (mid % playgrounds[i] == 0) {
					if (N == begin) {
						printf("%d\n", i + 1);
						return 0;
					}
					begin += 1;
				}
			}
		}
	}

	return 0;
}