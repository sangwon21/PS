#include <iostream>
#include <stack>
#include <map>

int main()
{
	std::string s;

	std::cin >> s; 

	int ducks[601];
	int duckCount = 0;
	char sound[5] = { 'q', 'u', 'a', 'c', 'k' };
	std::map<char, int> soundMap;

	soundMap['q'] = 0;
	soundMap['u'] = 1;
	soundMap['a'] = 2;
	soundMap['c'] = 3;
	soundMap['k'] = 4;

	for (int i = 0; i < 601; i++)
	{
		ducks[i] = -1;
	}

	if (s.size() % 5 != 0)
	{
		std::cout << -1 << std::endl;
		return 0;
	}

	for (int i = 0; i < s.size(); i++)
	{
		char target = s[i];
		bool hasFound = false;

		for (int j = 0; j < duckCount; j++)
		{
			int convertedSound = soundMap[target];
			if (ducks[j] == convertedSound - 1)
			{
				ducks[j]++;
				ducks[j] = ducks[j] == 4 ? -1 : ducks[j];
				hasFound = true;
				break;
			}
		}
		if (!hasFound)
		{
			if (target == 'q')
			{
				ducks[duckCount] = 0;
				duckCount++;
				continue;
			}
			else
			{
				std::cout << -1 << std::endl;
				return 0;
			}
		}
	}

	for (int i = 0; i < duckCount; i++)
	{
		if (ducks[i] != -1)
		{
			std::cout << -1 << std::endl;
			return 0;
		}
	}


	std::cout << duckCount << std::endl;

	return 0;
}