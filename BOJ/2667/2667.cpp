#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int list[25][25];
bool check[25][25];
int length;
int ans[626];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void go(int y, int x, int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		int newY = y + dy[i];
		int newX = x + dx[i];

		if (0 <= newX && newX < length && 0 <= newY && newY < length)
		{
			if (list[newY][newX] == 1 && check[newY][newX] == false)
			{
				check[newY][newX] = true;
				list[newY][newX] = cnt;
				go(newY, newX, cnt);
			}
		}
	}
}

int main(void)
{
	scanf("%d", &length);

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			scanf("%1d", &list[i][j]);
		}
	}

	int cnt = 1;
	
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (list[i][j] == 1 && check[i][j] == false)
			{
				go(i, j, ++cnt);
			}
		}
	}
	
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			ans[list[i][j]] += 1;
		}
	}
	printf("%d\n", cnt - 2);
	for (int i = 2; i < cnt; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}