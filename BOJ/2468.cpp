#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

#define SOAKED 1
#define UNTOUCHED 0
#define TOUCHED 2

int map[1000][1000];
int check[1000][1000];
int maxDepth = 0;
int length;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 0;

void rain(int rainDepth)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (map[i][j] <= rainDepth)
			{
				check[i][j] = SOAKED;
			}
		}
	}
}

bool isValid(int y, int x)
{
	return 0 <= y && y < length && 0 <= x && x < length;
}

void dfs(int y, int x)
{
	check[y][x] = TOUCHED;
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		
		if (isValid(nextY, nextX) && check[nextY][nextX] == UNTOUCHED)
		{
			dfs(nextY, nextX);
		}
	}
}

int main(void)
{
	std::cin >> length;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			scanf("%d", &map[i][j]);
			if (maxDepth < map[i][j])
			{
				maxDepth = map[i][j];
			}
		}
	}

	while (maxDepth > -1)
	{
		memset(check, UNTOUCHED, sizeof(check));
		rain(maxDepth);
		int cnt = 0;
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (check[i][j] == UNTOUCHED)
				{
					dfs(i, j);
					cnt += 1;
				}
			}
		}
		if (ans < cnt)
		{
			ans = cnt;
		}
		maxDepth--;
	}
	printf("%d\n", ans);
	return 0;
}