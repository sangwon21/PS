#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int R, C;
char map[20][20];
bool check[20][20];
bool alphabet[26];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 0;

bool isValid(int x, int y)
{
	return 0 <= x && x < C && 0 <= y && y < R;
}

void go(int x, int y, int cnt)
{
	
	if (cnt > ans)
	{
		ans = cnt;
	}
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (isValid(nextX, nextY))
		{
			if (alphabet[map[nextY][nextX] - 'A'] == false)
			{
				if (check[nextY][nextX] == false)
				{
					alphabet[map[nextY][nextX] - 'A'] = true;
					check[nextY][nextX] = true;
					go(nextX, nextY, cnt + 1);
					check[nextY][nextX] = false;
					alphabet[map[nextY][nextX] - 'A'] = false;
				}
			}
		}
	}
}
int main(void)
{
	std::cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			std::cin >> map[i][j];
		}
	}
	
	check[0][0] = true;
	alphabet[map[0][0] - 'A'] = true;

	
	go(0, 0, 0);

	std::cout << ans + 1 << '\n';
	return 0;
}