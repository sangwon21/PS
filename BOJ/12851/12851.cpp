#include <iostream>
#include <queue>
#include <tuple>

static int N;
static int sister;
static int ansTime = 0;
static int ansCount = 0;
static int timeArray[100002] = { 100000, };

static void BFS()
{
	std::fill(timeArray, timeArray + 100001, 100000);
	std::queue<std::pair<int, int>> q;
	q.push({ N, 0 });
	timeArray[N] = 0;

	while (q.empty() == false)
	{
		int subin, currTime;
		std::tie(subin, currTime) = q.front();
		q.pop();

		timeArray[subin] = currTime;

		if (ansTime != 0)
		{
			if (currTime == ansTime && subin == sister)
			{
				++ansCount;
			}
			continue;
		}

		if (subin == sister)
		{
			ansTime = currTime;
			++ansCount;
			continue;
		}
		
		int nextSubin = subin - 1;
		int nextTime = currTime + 1;
		
		if (0 <= nextSubin && nextSubin <= 100000)
		{
			if (timeArray[nextSubin] >= nextTime)
			{
				q.push({ nextSubin, nextTime });
			}
		}

		nextSubin = subin + 1;

		if (0 <= nextSubin && nextSubin <= 100000)
		{
			if (timeArray[nextSubin] >= nextTime)
			{
				q.push({ nextSubin, nextTime });
			}
		}

		nextSubin = subin * 2;

		if (0 <= nextSubin && nextSubin <= 100000)
		{
			if (timeArray[nextSubin] >= nextTime)
			{
				q.push({ nextSubin, nextTime });
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> sister;
	BFS();

	std::cout << ansTime << std::endl;
	std::cout << ansCount << std::endl;
	return 0;
}