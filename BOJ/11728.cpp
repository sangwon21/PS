#include <iostream>

using namespace std;

int A[1000000];
int B[1000000];
int C[2000000];

int main(void) {
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		cin >> A[i];
	}

	for (int j = 0; j < b; j++) {
		cin >> B[j];
	}

	int c = 0;
	int aIdx = 0;
	int bIdx = 0;
	while(aIdx < a && bIdx < b){
		if (A[aIdx] < B[bIdx]) {
			C[c++] = A[aIdx++];
		}
		else {
			C[c++] = B[bIdx++];
		}
	}

	while (aIdx < a) {
		C[c++] = A[aIdx++];
	}
	
	while (bIdx < b) {
		C[c++] = B[bIdx++];
	}

	for (int i = 0; i < c; i++) {
		printf("%d ", C[i]);
	}

	return 0;
}