#include <iostream>

using namespace std;

int n;
int num[8];
bool check[8];

int minNum = 0;

void dfs(int curIdx) {
	if (curIdx == n) {
		
	}
	for (int i = curIdx; i < n; i++) {
		if (check[i] == false) {
			check[i] = true;
			dfs(i);
			check[i] = false;
		}
	}
}
int main(void) {
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	
	return 0;
}