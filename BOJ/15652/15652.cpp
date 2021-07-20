#include <iostream>

int N, M;
int arr[10];
bool check[10];

void go(int idx, int start) {
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
		return;
	}

	for (int i = start; i <= N; i++) {
		arr[idx] = i;
		go(idx + 1, i);
	}
}

int main(void) {

	std::cin >> N >> M;

	go(0, 1);
	return 0;
}