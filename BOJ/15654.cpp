#include <iostream>
#include <algorithm>

int N, M;

bool check[10];
int arr[10];
int ans[10];

void go(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			std::cout << ans[i] << ' ';
		}
		std::cout << '\n';
	}
	for (int i = 1; i <= N; i++) {
		if (check[i]) continue;
		check[i] = true;
		ans[idx] = arr[i];
		go(idx + 1);
		check[i] = false;
	}
}

int main(void) {

	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		std::cin >> arr[i];
	}

	std::sort(arr + 1, arr + N + 1);

	go(0);

	return 0;
}