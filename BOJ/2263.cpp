#include <iostream>

using namespace std;

int n;
int inOrder[100001];
int postOrder[100001];
int position[100001];

void solve(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe) return;
	int root = postOrder[pe];
	printf("%d ", root);
	int ir = position[root];

	int left = ir - is;
	solve(is, ir - 1, ps, ps + left - 1);
	solve(ir + 1, ie, ps + left, pe - 1);
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &inOrder[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &postOrder[i]);
	}

	for (int i = 0; i < n; i++) {
		position[inOrder[i]] = i;
	}

	solve(0, n - 1, 0, n - 1);
	return 0;
}