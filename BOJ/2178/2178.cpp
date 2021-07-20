#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

int N, M;
int map[100][100];
bool check[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 0;

struct loc {
	int y;
	int x;
};
void go(int y, int x)
{
	using namespace std;

	queue<pair<loc, int>> q;
	q.push(make_pair(loc{ y, x }, 1));
	check[y][x] = true;

	while (!q.empty())
	{
		int currentY = q.front().first.y;
		int currentX = q.front().first.x;
		int distance = q.front().second;
		q.pop();

		if (currentY == N - 1 && currentX == M - 1)
		{
			ans = distance;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nextY = currentY + dy[i];
			int nextX = currentX + dx[i];

			if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M)
			{
				if (check[nextY][nextX] == false && map[nextY][nextX] == 1)
				{
					check[nextY][nextX] = true;
					q.push(make_pair(loc{ nextY, nextX }, distance + 1));
				}
			}
		}
	}
}


int main(void)
{
	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d",&map[i][j]);
		}
	}

	go(0, 0);
	
	std::cout << ans << '\n';

	return 0;
}