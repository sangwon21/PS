#include <iostream>

int N, M;
int arr[10];
bool check[10];

void go(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		
		arr[idx] = i;
		go(idx + 1);
		
	}
}

int main(void) {

	std::cin >> N >> M;

	go(0);
	return 0;
}