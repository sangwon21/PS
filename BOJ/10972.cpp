#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int numArray[10001];

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

bool nextPermutation(int * arr, int n) {
	int i = n - 1;
	while (i > 0 && arr[i - 1] >= arr[i]) i -= 1;
	if (i <= 0)return false;
	int j = n - 1;
	while (arr[j] <= arr[i - 1]) j--;
	swap(arr[j], arr[i - 1]);
	j = n - 1;
	while (i < j) {
		swap(arr[j], arr[i]);
		i = i + 1;
		j = j - 1;
	}
	return true;
}

int main(void) {
	int numSize;
	scanf("%d", &numSize);
	for (int i = 0; i < numSize; i++) {
		scanf("%d", &numArray[i]);
	}

	if (nextPermutation(numArray, numSize)) {
		for (int i = 0; i < numSize; i++) {
			printf("%d ", numArray[i]);
		}
	}
	else {
		printf("-1");
	}
	cout << '\n';
	return 0;
}