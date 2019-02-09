#include <iostream>
#include <string>
#include <algorithm>

#define ALPAH_NUM 26

using namespace std;


int l, c;
char alpha[16];
bool check[16];

bool isValid(string s) {
	int mo = 0, ja = 0;
	for (int i = 0; i < l; i++) {
		switch (s[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			mo++;
			break;
		default:
			ja++;
			break;
		}
	}
	return mo >= 1 && ja >= 2;
}
void dfs(string s, int curIdx) {
	if (s.length() == l) {
		if (isValid(s)) {
			for (int i = 0; i < l; i++) {
				cout << s[i];
			}
			printf("\n");
		}
		return;
	}
	for (int i = curIdx; i < c; i++) {
		
			check[i] = true;
			dfs(s + alpha[i], i + 1);
			check[i] = false;
		
	}
}

int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> alpha[i];
	}

	// sort
	sort(alpha, alpha + c);

	dfs("", 0);

	return 0;
}