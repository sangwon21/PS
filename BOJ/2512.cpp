#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int budgetCounts;
int budgets[10001];
int sumLimit;
int maxBudget = 0;

bool isValidBudget(int budgetLimit)
{
	long long sum = 0;
	for (int i = 0; i < budgetCounts; i++)
	{
		if (budgets[i] >= budgetLimit)
		{
			sum += budgetLimit;
		}
		else
		{
			sum += budgets[i];
		}
	}
	return sumLimit >= sum;
}

int main(void)
{

	
	scanf("%d", &budgetCounts);

	for (int i = 0; i < budgetCounts; i++)
	{
		scanf("%d", &budgets[i]);

		if (maxBudget < budgets[i])
		{
			maxBudget = budgets[i];
		}
	}
	scanf("%d", &sumLimit);

	int left = 0;
	int right = maxBudget;
	int ans = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (isValidBudget(mid))
		{
			if (ans < mid)
			{
				ans = mid;
			}

			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	printf("%d\n", ans);
}