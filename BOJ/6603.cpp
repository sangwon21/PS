#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
	
	while (true) {
		int n;
		std::cin >> n;
		if (n == 0) break;
		std::vector<int> v;
		for (int i = 0; i < n; i++) {
			int tmp;
			std::cin >> tmp;
			v.push_back(tmp);
		}

		std::vector<int> zeros;
		for (int i = 0; i < 6; i++) {
			zeros.push_back(0);
		}
		for (int i = 6; i < n; i++) {
			zeros.push_back(1);
		}

		do {
			for (int i = 0; i < n; i++) {
				if (zeros[i] == 0) {
					std::cout << v[i] << " ";
				}
			}

			std::cout << std::endl;
		} while (std::next_permutation(zeros.begin(), zeros.end()));
		std::cout << std::endl;
	}

	return 0;
}