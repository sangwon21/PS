#include <iostream>
#include <vector>
#include <algorithm>

int n;
int w[10][10];
std::vector<int> v;
int min = 9999999;

int main(void) {

	std::cin >> n;

	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> w[i][j];
		}
		v.push_back(i);
	}

	do {
		int cur = v[0];
		int ans = 0;
		bool flag = true;
		for (int i = 0; i < (int)v.size(); i++) {
			if (v[i] == cur) continue;
			if (w[cur][v[i]] == 0) { 
				flag = false;
				break; 
			}
			ans += (w[cur][v[i]]);
			cur = v[i];
		}
		if (flag && w[v[(int)v.size() - 1]][v[0]] != 0) {
			ans += w[v[(int)v.size() - 1]][v[0]];
			if (flag && ans < min) min = ans;
		}
	} while (std::next_permutation(v.begin(), v.end()));

	std::cout << min << std::endl;

	return 0;
}