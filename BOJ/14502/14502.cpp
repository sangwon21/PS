#include <iostream>
#include <vector>
#include <algorithm>

static int width;
static int height;
static int lab[100][100];
static int clonedLab[100][100];
static int visitedLab[100][100];
static enum STAUTS {
	BLANK = 0,
	WALL = 1, 
	VIRUS = 2
};

static std::vector<std::pair<int, int>> blankVector;
static const int WALL_LIMIT_COUNT = 3;
static int ans = 0;
static int indexCombination[3];
static int dx[4] = { -1, 1, 0, 0 };
static int dy[4] = { 0, 0, -1, 1 };

static void cloneLab()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			visitedLab[i][j] = 0;
			clonedLab[i][j] = lab[i][j];
		}
	}
}

static void putWallOnTheLab()
{
	cloneLab();
	for (int i = 0; i < WALL_LIMIT_COUNT; ++i)
	{
		std::pair<int, int> targetCoordinate = blankVector[indexCombination[i]];
		clonedLab[targetCoordinate.first][targetCoordinate.second] = WALL;
	}
}

static void dfs(int y, int x)
{
	visitedLab[y][x] = 1;
	clonedLab[y][x] = VIRUS;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (0 > ny || ny >= height || 0 > nx || nx >= width)
		{
			continue;
		}
		if (clonedLab[ny][nx] != BLANK || visitedLab[ny][nx] == 1)
		{
			continue;
		}
		
		dfs(ny, nx);
	}
}

static void processVirus()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (clonedLab[i][j] == VIRUS && visitedLab[i][j] == false)
			{
				dfs(i, j);
			}
		}
	}
}

static int countSafeArea()
{
	int safeAreaCount = 0;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (clonedLab[i][j] == BLANK)
			{
				++safeAreaCount;
			}
		}
	}
	return safeAreaCount;
}


static void combination(int depth, int next)
{
	if (depth == WALL_LIMIT_COUNT)
	{
		putWallOnTheLab();
		processVirus();
		ans = std::max(ans, countSafeArea());
		return;
	}
	
	for (int i = next; i < blankVector.size(); ++i)
	{
		indexCombination[depth] = i;
		combination(depth + 1, i + 1);
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> height >> width;

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cin >> lab[i][j];
			if (lab[i][j] == BLANK)
			{
				blankVector.push_back(std::pair<int, int>(i, j));
			}
		}
	}

	combination(0, 0);

	std::cout << ans << std::endl;

	return 0;
}