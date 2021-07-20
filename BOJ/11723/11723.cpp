#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int main(void) {

	int testcase;
	cin >> testcase;
	char buf[111];
	int n = 20;
	int bits = 0;

	while (testcase--) {
		scanf("%s", buf);
		if (!strcmp(buf, "add")) {
			int i = 0;
			scanf("%d", &i); i--;
			bits = bits | (1 << i);
		}
		else if (!strcmp(buf, "check")) {
			int i = 0; 
			scanf("%d", &i); i--;
			int res = bits & (1 << i);
			if (res) {
				puts("1");
			}
			else {
				puts("0");
			}
		}
		else if (!strcmp(buf, "remove")) {
			int i = 0;
			scanf("%d", &i); i--;
			bits = bits & ~(1 << i);
		}
		else if (!strcmp(buf, "toggle")) {
			int i = 0;
			scanf("%d", &i); i--;
			bits = bits ^ (1 << i);
		}
		else if (!strcmp(buf, "all")) {
			bits = (1 << n) - 1;
		}
		else if (!strcmp(buf, "empty")) {
			bits = 0;
		}
	}

	return 0;
}