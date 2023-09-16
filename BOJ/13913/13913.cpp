#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

static int subin;
static int sister;
static int timeArr[200004];
static int prevArr[200004];
static int ansTime = 0;

static void BFS()
{
	std::fill(timeArr, timeArr + 100001, 100000);
	std::fill(prevArr, prevArr + 100001, 0);

	std::queue <std::pair<int, int>> q;
	q.push({ subin, 0 });
	timeArr[subin] = 0;
	prevArr[subin] = 0;


	while (q.empty() == false)
	{
		int currSubin, currTime;
		std::tie(currSubin, currTime) = q.front();
		q.pop();

		if (currSubin == sister)
		{
			ansTime = currTime;
			break;
		}

		int nextSubin = currSubin + 1;
		int nextTime = currTime + 1;

		if (0 <= nextSubin && nextSubin <= 100000)
		{
			if (timeArr[nextSubin] > nextTime)
			{
				timeArr[nextSubin] = nextTime;
				prevArr[nextSubin] = currSubin;
				q.push({ nextSubin, nextTime });
			}
		}

		nextSubin = currSubin - 1;
		if (0 <= nextSubin && nextSubin <= 100000)
		{
			if (timeArr[nextSubin] > nextTime)
			{
				timeArr[nextSubin] = nextTime;
				prevArr[nextSubin] = currSubin;
				q.push({ nextSubin, nextTime });
			}
		}

		nextSubin = currSubin * 2;
		if (0 <= nextSubin && nextSubin <= 100000)
		{
			if (timeArr[nextSubin] > nextTime)
			{
				timeArr[nextSubin] = nextTime;
				prevArr[nextSubin] = currSubin;
				q.push({ nextSubin, nextTime });
			}
		}
	}
}

static void PrintTimeline()
{
	std::vector<int> v;

	v.push_back(sister);

	int prevPosition = prevArr[sister];
	while (prevPosition)
	{
		v.push_back(prevPosition);
		prevPosition = prevArr[prevPosition];
	}

	if (subin == 0 && sister != 0)
	{
		v.push_back(0);
	}

	for (int i = v.size() - 1; i >= 0; --i)
	{
		std::cout << v[i] << " ";
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> subin >> sister;

	BFS();

	std::cout << ansTime << std::endl;
	PrintTimeline();

	return 0;
}