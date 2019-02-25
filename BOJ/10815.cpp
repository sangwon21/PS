#include <iostream>
#include <algorithm>

#define MAX_NUM 500000
using namespace std;

int n;
int numbers[MAX_NUM];
int targets[MAX_NUM];
int n2;

int binarySearch(int target) {
	int left = 0, right = n - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (numbers[mid] == target) {
			return 1;
		}
		else if (numbers[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return 0;
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
		targets[i] = binarySearch(targets[i]);
	}
	
	for (int i = 0; i < n2; i++) {
		cout << targets[i] <<' ';
	}

	return 0;
}