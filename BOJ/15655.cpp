#include <iostream>
#include <algorithm>

int N, M;
int arr[10];
int ans[10];

void go(int idx, int start) {
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			std::cout << ans[i] << ' ';
		}
		std::cout << '\n';

		return;
	}
	
	for (int i = start; i <= N; i++) {
		ans[idx] = arr[i];
		go(idx + 1, i + 1);
	}
}

int main(void) {

	std::cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		std::cin >> arr[i];
	}

	std::sort(arr + 1, arr + N + 1);

	go(0, 1);

	return 0;
}