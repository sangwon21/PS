#include <iostream>

int dp[1001];
int chocolates[1001];
int num;

int main(void)
{
	std::cin >> num;

	for (int i = 0; i < num; i++)
	{
		std::cin >> chocolates[i];
	}

	dp[0] = 1;
	int maxChocolates = dp[0];

	for (int i = 1; i < num; i++)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (chocolates[j] < chocolates[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				if (dp[i] >= maxChocolates)
				{
					maxChocolates = dp[i];
				}
			}
		}
	}

	std::cout << maxChocolates << std::endl;

	return 0;
}