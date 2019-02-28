#include <iostream>

using namespace std;

void hanoi(int x, int y, int n) {
	if (n == 0) return;
	hanoi(x, y, n - 1);
	printf("%d %d\n", x, 6 - x - y);
	hanoi(y, 6 - x - y, n - 1);
}

int main(void) {

	hanoi(1, 2, 3);
	return 0;
}