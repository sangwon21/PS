#include <iostream>
#include <algorithm>

#define MAX_NUM 500000
using namespace std;

int n;
int numbers[MAX_NUM];
int targets[MAX_NUM];
int cache[20000001];
int n2;

int binarySearch(int target, int left, int right) {
	int result = 0;
	if (left <= right) {
		int mid = left + (right - left) / 2;

		if (target > numbers[mid]) {
			result += binarySearch(target, mid + 1, right);
		}
		else if (target < numbers[mid]) {
			result += binarySearch(target, left, mid - 1);
		}
		else {
			result += binarySearch(target, mid + 1, right);
			result += binarySearch(target, left, mid - 1);
			result += 1;
		}
		return result;
	}
	else {
		return 0;
	}
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	sort(numbers, numbers + n);

	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> targets[i];
	}

	for (int i = 0; i < n2; i++) {
		if (cache[targets[i] + 10000000] == 0) {
			cache[targets[i] + 10000000] = binarySearch(targets[i], 0, n);
		}

		printf("%d ", cache[targets[i] + 10000000]);
	}

	return 0;
}