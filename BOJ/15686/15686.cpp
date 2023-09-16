#include <iostream>
#include <vector>
#include <limits>

static int N;
static int M;
static int city[51][51];
static std::vector<std::pair<int, int>> restaurantPositionVector;
static std::vector<std::pair<int, int>> housePositionVector;
static std::pair<int, int> pairArr[14];
static int ans = std::numeric_limits<int>::max();

enum STATUS {
	BLANK = 0,
	HOUSE = 1,
	CHICKEN_RESTAURANT = 2
};

static void calculateDistance(int limit)
{
	int tmpAns = 0;
	for (int i = 0; i < housePositionVector.size(); ++i)
	{
		int tmp = std::numeric_limits<int>::max();
		const std::pair<int, int> housePosition = housePositionVector[i];
		for (int j = 0; j < limit; ++j)
		{
			const std::pair<int, int> remainRestaurantPosition = pairArr[j];
			
			tmp = std::min(tmp, 
				std::abs(housePosition.first - remainRestaurantPosition.first) +
				std::abs(housePosition.second - remainRestaurantPosition.second));
		}
		tmpAns += tmp;
	}
	ans = std::min(ans, tmpAns);
}

static void combination(int depth, int next, int level)
{
	if (depth == level)
	{
		calculateDistance(level);
		return;
	}

	for (int i = next; i < restaurantPositionVector.size(); ++i)
	{
		pairArr[depth] = restaurantPositionVector[i];
		combination(depth + 1, i + 1, level);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cin >> city[i][j];

			if (city[i][j] == CHICKEN_RESTAURANT)
			{
				restaurantPositionVector.push_back(std::pair<int, int>(i, j));
			}
			else if (city[i][j] == HOUSE)
			{
				housePositionVector.push_back(std::pair<int, int>(i, j));
			}
		}
	}

	for (int i = 1; i <= M; ++i)
	{
		combination(0, 0, i);
	}

	std::cout << ans << std::endl;

	return 0;
}