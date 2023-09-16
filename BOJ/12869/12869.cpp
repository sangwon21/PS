#include <iostream>
#include <queue>
#include <tuple>

static int N;
static int area[65][65][65] = { 0, };
static int visited[65][65][65] = { 0, };
static int mutal[3] = { 0, };

static int attack[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 9, 3},
	{1, 3, 9}
};

static int BFS(int a, int b, int c)
{
	std::queue<std::tuple<int, int, int>> q;
	q.push({ a, b, c });
	visited[a][b][c] = 1;

	while (q.empty() == false)
	{
		int ca, cb, cc;
		std::tie(ca, cb, cc) = q.front();
		q.pop();

		if (visited[0][0][0])
		{
			break;
		}

		for (int i = 0; i < 6; ++i)
		{
			int na = std::max(0, ca - attack[i][0]);
			int nb = std::max(0, cb - attack[i][1]);
			int nc = std::max(0, cc - attack[i][2]);

			if (visited[na][nb][nc])
			{
				continue;
			}

			visited[na][nb][nc] = visited[ca][cb][cc] + 1;
			q.push({ na, nb, nc });
		}
	}

	return visited[0][0][0] - 1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int tmp;
		std::cin >> mutal[i];
	}

	int ans = BFS(mutal[0], mutal[1], mutal[2]);

	std::cout << ans << std::endl;

	return 0;
}