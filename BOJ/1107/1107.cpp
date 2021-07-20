#include <iostream>

int target;
bool broken[10];
int brokenNum;

int isValid(int num) {
	if (num == 0)
		return broken[0] ? 0 : 1;
	
	int length = 0;

	while (num > 0) {
		int cmp = num % 10;
		if (broken[cmp] == true) return 0;
		num = num / 10;
		length += 1;
	}

	return length;
}

int main(void) {
	std::cin >> target;

	std::cin >> brokenNum;

	for (int i = 0; i < brokenNum; i++) {
		int tmp;
		std::cin >> tmp;
		broken[tmp] = true;
	}
	
	int min = (target - 100) > 0 ? (target - 100) : -(target - 100);
	int len;
	for (int i = 0; i < 1000001; i++) {
		if (len = isValid(i)) {
			int cmp = (target - i) > 0 ? (target - i) : -(target - i);
			cmp += len;
			if (cmp < min)
				min = cmp;
		}
	}
	std::cout << min;
	return 0;
}