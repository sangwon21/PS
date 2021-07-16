#include <iostream>
#include <vector>

int N;
int target;

int main()
{
	std::cin >> N;
	std::cin >> target;


	std::vector<std::vector<int>> v;

	for (int i = 0; i < N; i++)
	{
		std::vector<int> inner(N);
		v.push_back(inner);
	}

	int y = 0;
	int x = 0;
	int direction = 0; // 0 down 1 right 2 up 3 left
	int half = N / 2; 
	int num = N * N;
	int targetY;
	int targetX;
	int limitLength = N;
	int count = 1;

	while (x != half || y != half)
	{
		if (target == num)
		{
			targetY = y;
			targetX = x;
		}

		if (direction == 0) 
		{
			v[y][x] = num;
			
			// reached the downmost point
			if (count == limitLength)
			{
				direction = 1;
				x++;
				count = 1;
				num--;
				continue;
			}
			
			y++;
			num--;
			count++;
		}
		else if (direction == 1)
		{
			v[y][x] = num;
			
			// reached the rightmost point
			if (count == limitLength - 1)
			{
				direction = 2;
				y--;
				count = 1;
				num--;
				continue;
			}
			
			x++;
			num--;
			count++;
		}
		else if (direction == 2)
		{
			v[y][x] = num;

			// reached the upmost point
			if (count == limitLength - 1)
			{
				direction = 3;
				x--;
				count = 1;
				num--;
				continue;
			}

			y--;
			num--;
			count++;
		}
		else if (direction == 3)
		{
			v[y][x] = num;

			// reached the leftmost point
			if (count == limitLength - 2)
			{
				direction = 0;
				y++;
				count = 1;
				limitLength -= 2;
				num--;
				continue;
			}

			x--;
			num--;
			count++;
		}
	}

	v[half][half] = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << v[i][j] << " ";
		}
		std::cout << '\n';
	}

	if (target == 1) 
	{
		std::cout << half << ' ' << half << '\n';
	}
	else
	{
		std::cout << targetY + 1 << ' ' << targetX + 1 << '\n';
	}

	
	return 0;
}