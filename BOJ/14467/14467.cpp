#include <iostream>

int record[20];
int N;

int main()
{
	std::cin >> N;
	int cow, pos;
	int ans = 0;

	for (int i = 0; i < 11; i++)
	{
		record[i] = -1;
	}

	for (int i = 0; i < N; i++)
	{
		std::cin >> cow >> pos;
		if (record[cow] == -1) {
			record[cow] = pos;
			continue;
		}
		if (record[cow] != pos)
		{
			record[cow] = pos;
			ans++;
		}
	}

	std::cout << ans;

	return 0;
}