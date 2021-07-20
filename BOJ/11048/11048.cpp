#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

int N, M;
int map[1000][1000];
int dp[1000][1000];

int go(int y, int x)
{

	if (y == 0 && x == 0)
	{
		return map[0][0];
	}

	if (y < 0 || y >= N || x < 0 || x >= M)
	{
		return 0;
	}

	if (dp[y][x] >= 0)
	{
		return dp[y][x];
	}

	dp[y][x] = map[y][x] + std::max(go(y - 1, x - 1), std::max(go(y - 1, x), go(y, x - 1)));

	return dp[y][x];
}

int main(void)
{
	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	
	memset(dp, -1, sizeof(dp));
	int ans = go(N - 1, M - 1);
	printf("%d", ans);
	return 0;
}