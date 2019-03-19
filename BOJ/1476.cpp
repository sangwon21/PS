#include <iostream>

int e, s, m;

int main(void) {
	std::cin >> e >> s >> m;

	int ans = 1;
	int e1 = 1, s1 = 1, m1 = 1;

	while (true) {
		if (e1 == e && s1 == s && m1 == m) break;
		e1 += 1;
		s1 += 1;
		m1 += 1;
		ans += 1;
		if (e1 >= 16)
			e1 = 1;
		if (s1 >= 29)
			s1 = 1;
		if (m1 >= 20)
			m1 = 1;
	}

	std::cout << ans << std::endl;

	return 0;
}