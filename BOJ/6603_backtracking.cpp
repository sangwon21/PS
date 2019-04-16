#include <iostream>

int balls[13];
int check[13];
int num;

void printLotto() {
	for (int i = 0; i < 6; i++) {
		std::cout << balls[i] << ' ';
	}
	std::cout << std::endl;
}

void go(int idx, int depth) {
	if (depth == 6) {
		printLotto();
		return;
	}

	for (int i = idx; i < num; i++) {
		if (check[i] == false) {
			check[i] = true;
			std::swap(balls[i], balls[depth]);
			go(i + 1, depth + 1);
			std::swap(balls[i], balls[depth]);
			check[i] = false;
		}
	}
}


int main(void) {
	while (true) {
		
		std::cin >> num;
		if (num == 0) break;
		for (int i = 0; i < num; i++) {
			std::cin >> balls[i];
		}

		go(0, 0);

		std::cout << std::endl;

	}

}