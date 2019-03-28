#include <iostream>

int N, M;

bool check[9];
int arr[9];

void go(int idx, int startIdx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
		return;
	}

	for (int i = startIdx; i <= N; i++) {
		if (check[i]) continue;
		check[i] = true;
		arr[idx] = i;
		go(idx + 1, i + 1);
		check[i] = false;
	}
}

int main(void) {
	std::cin >> N >> M;

	go(0, 1);

	return 0;
}