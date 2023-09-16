#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
#include <vector>

static const int LENGTH = 52;
static int N;
static int L;
static int R;
static int area[LENGTH][LENGTH];
static bool visited[LENGTH][LENGTH];
static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };
static int ans = 0;

static void InitializeData()
{
	memset(visited, false, LENGTH * LENGTH);
}

static bool BFS(std::pair<int, int> startPosition)
{
	std::vector<std::pair<int, int>> v;
	std::queue<std::pair<int, int>> q;
	q.push(startPosition);
	v.push_back(startPosition);

	visited[startPosition.first][startPosition.second] = true;
	int sum = area[startPosition.first][startPosition.second];

	while (q.empty() == false)
	{
		int x, y;
		std::tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 > ny || ny >= N || 0 > nx || nx >= N)
			{
				continue;
			}

			if (visited[ny][nx] == true)
			{
				continue;
			}

			const int diff = std::abs(area[y][x] - area[ny][nx]);

			if (!(L <= diff && diff <= R))
			{
				continue;
			}

			visited[ny][nx] = true;
			q.push({ ny, nx });
			v.push_back({ ny, nx });
			sum += area[ny][nx];
		}
	}

	const int nextSum = sum / v.size();
	for (int i = 0; i < v.size(); ++i)
	{
		int x, y;
		std::tie(y, x) = v[i];
		area[y][x] = nextSum;
	}

	return v.size() == 1;
}



static void Print()
{
	std::cout << "========================================" << std::endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cout << area[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "========================================" << std::endl;
}

static void Simulate()
{
	while (true)
	{
		InitializeData();

		bool stopFlag = true;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (visited[i][j] == true)
				{
					continue;
				}
				bool tmpFlag = BFS({ i, j });
				if (tmpFlag == false) 
				{
					stopFlag = false;
				}
			}
		}

		if (stopFlag)
		{
			break;
		}

		ans++;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> L >> R;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cin >> area[i][j];
		}
	}

	Simulate();

	std::cout << ans << std::endl;

	return 0;
}