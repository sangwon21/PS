#include <iostream>

int n;
int s[8];
int w[8];
int answer = 0;

void dfs(int cur)
{
	if (cur >= n)
	{
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] <= 0)
			{
				ans++;
			}
		}
		answer = answer > ans ? answer : ans;
		return; 
	}

	if (s[cur] <= 0)
	{
		dfs(cur + 1);
	}
	else
	{
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			if (i == cur || s[i] <= 0)
			{
				continue;
			}
			flag = true;
			s[i] -= w[cur];
			s[cur] -= w[i];
			dfs(cur + 1);
			s[i] += w[cur];
			s[cur] += w[i];
		}

		if (!flag)
		{
			dfs(n);
		}
	}

}

int main()
{
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> s[i] >> w[i];
	}

	dfs(0);

	std::cout << answer << std::endl;

	return 0;
}