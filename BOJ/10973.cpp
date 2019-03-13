#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int sizeArr;
int arr[10001];

void swap(int &a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

bool previousPermutation(int * v, int n) {
	int i = n - 1;

	while (i > 0 && v[i - 1] <= v[i]) i--;
	if (i <= 0) return false;
	int j = n - 1;
	while (v[i - 1] <= v[j]) j--;
	swap(v[i - 1], v[j]);
	j = n - 1;
	while (i < j) {
		swap(v[i], v[j]);
		i++; j--;
	}
	return true;
}


int main(void) {
	scanf("%d", &sizeArr);

	for (int i = 0; i < sizeArr; i++) {
		cin >> arr[i];
	}

	if (previousPermutation(arr, sizeArr)) {
		for (int i = 0; i < sizeArr; i++) {
			printf("%d ", arr[i]);
		}
	}
	else {
		printf("-1");
	}

	printf("\n");
	
	return 0;
}