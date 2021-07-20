#include <iostream>
#include <queue>

int w, h;
int map[50][50];
int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
bool check[50][50];

void go(int y, int x)
{
	using namespace std;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	check[y][x] = true;

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;

		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];
			
			if (0 <= nextY && nextY < w && 0 <= nextX && nextX < h)
			{
				if (check[nextY][nextX] == false && map[nextY][nextX] == 1)
				{
					check[nextY][nextX] = true;
					q.push(make_pair(nextY, nextX));
				}
			}
		}
	}
}
int main(void)
{
	
	while (true)
	{
		std::cin >> h >> w;

		if (w == 0 && h == 0)
		{
			break;
		}

		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				std::cin >> map[i][j];
			}
		}

		int cnt = 0;

		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				if (map[i][j] == 1 && check[i][j] == false)
				{
					go(i, j);
					cnt += 1;
				}
			}
		}

		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				map[i][j] = 0;
				check[i][j] = false;
			}
		}
		std::cout << cnt << '\n';
	}
	

	return 0;
}