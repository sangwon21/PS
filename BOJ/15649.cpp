#include <iostream>

int N, M;
int arr[8];
bool check[8];

void go(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		if (check[i]) continue;
		check[i] = true;
		arr[idx] = i + 1;
		go(idx + 1);
		check[i] = false;
	}
}
int main(void) {
	std::cin >> N >> M;
	
	go(0);

	return 0;
}