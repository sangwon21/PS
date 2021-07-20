#include <iostream>
#include <queue>
#include <vector>
int R, C;
char map[50][50];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0, 0,-1,1 };
struct Pos
{
	int y;
	int x;

	bool operator==(Pos& rhs)
	{
		return rhs.x == x && rhs.y == y;
	}
};

std::queue<Pos> waters;
Pos den;
Pos start;

bool isValid(Pos pos)
{
	return 0 <= pos.y && pos.y < R && 0 <= pos.x && pos.x < C;
}

int bfs()
{
	using namespace std;
	queue<pair<Pos, int>> place;

	place.push(make_pair(start, 0));

	while (!place.empty())
	{

		// 물 옮기기
		int waterSize = waters.size();
		for (int i = 0; i < waterSize; i++)
		{
			Pos currentWater = waters.front();
			waters.pop();
			for (int j = 0; j < 4; j++)
			{
				int y = currentWater.y + dy[j];
				int x = currentWater.x + dx[j];
				Pos tmp = { y,x };
				if (isValid(tmp) && map[y][x] != 'D' && map[y][x] != 'X' && map[y][x] != '*')
				{
					map[y][x] = '*';
					waters.push(Pos{ y,x });
				}
			}
		}

		int placeSize = place.size();

		for (int i = 0; i < placeSize; i++)
		{

			Pos currentPos = place.front().first;
			int currentDist = place.front().second;
			place.pop();

			for (int j = 0; j < 4; j++)
			{
				int y = currentPos.y + dy[j];
				int x = currentPos.x + dx[j];
				int dist = currentDist + 1;

				Pos tmp = { y,x };

				if (tmp == den)
				{
					return dist;
				}

				if (isValid(tmp) && map[y][x] == '.')
				{
					map[y][x] = 'S';
					place.push(make_pair(tmp, dist));
				}
			}		
		}
	}

	return -1;
}
int main(void)
{
	std::cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			std::cin >> map[i][j];
			if (map[i][j] == '*')
			{
				waters.push(Pos{ i, j });
			}
			else if (map[i][j] == 'D')
			{
				den = Pos{ i,j };
			}
			else if (map[i][j] == 'S')
			{
				start = Pos{ i,j };
			}
		}
	}

	int s = bfs();
	if (s == -1)
	{
		std::cout << "KAKTUS" << '\n';
	}
	else
	{
		std::cout << s << '\n';
	}
	return 0;
}