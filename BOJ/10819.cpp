#include <iostream>

int num;
int numArray[8];
int max = 0;

void swap(int * a, int * b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int cal() {
	int ans = 0;
	for (int i = 0; i < num - 1; i++) {
		int tmp = numArray[i] - numArray[i + 1];
		if (tmp < 0) tmp *= -1;
		ans += tmp;
	}
	return ans;
}

void go(int idx) {
	if (idx == num) {
		int tmp = cal();
		if (max < tmp) max = tmp;
		return;
	}

	for (int i = idx; i < num; i++) {
		swap(&numArray[idx], &numArray[i]);
		go(idx + 1);
		swap(&numArray[idx], &numArray[i]);
	}
}

int main(void) {

	std::cin >> num;

	for (int i = 0; i < num; i++) {
		std::cin >> numArray[i];
	}

	go(0);

	std::cout << max << std::endl;
	return 0;
}