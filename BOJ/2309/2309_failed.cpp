#include <iostream>
#include <algorithm>

using namespace std;

int dwarf[9];
bool check[9];

void dfs(int index, int numIncluded) {
	if (index == 9) {
		int sum = 0;
		for (int i = 0; i < 9; i++) {
			if (check[i] == true) {
				sum += dwarf[i];
			}
		}
		if (sum == 100) {
			for (int i = 0; i < 9; i++) {
				if (check[i] == true) {
					cout << dwarf[i] << endl;
				}
			}
			exit(1);
		}
	}
	for (int i = index; i < 9; i++) {
		if (check[i] == false) {
			check[i] = true;
			dfs(i + 1, numIncluded + 1);
			check[i] = false;
		}
		dfs(i + 1, numIncluded);
	}
}
int main(void) {

	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
	}
	sort(dwarf, dwarf + 9);
	dfs(0, 0);
	return 0;
}