#include <iostream>
#include <queue>

int subin;
int sister;
bool check[1000001];

int find()
{
	
	using namespace std;
	deque<pair<int, int>> q;
	q.push_back(make_pair(subin, 0));
	check[subin] = true;

	while (!q.empty())
	{
		int curSubin = q.front().first;
		int curTime = q.front().second;
		q.pop_front();

		if (curSubin == sister)
		{
			return curTime;
		}

		if (curSubin * 2 < 1000000 && check[curSubin * 2] == false)
		{
			check[curSubin * 2] = true;
			q.push_front(make_pair(curSubin * 2, curTime));
		}

		if (curSubin - 1 >= 0  && check[curSubin - 1] == false)
		{
			check[curSubin - 1] = true;
			q.push_back(make_pair(curSubin - 1, curTime + 1));
		}

		if ( curSubin + 1 < 1000000 && check[curSubin + 1] == false)
		{
			check[curSubin + 1] = true;
			q.push_back(make_pair(curSubin + 1, curTime + 1));
		}

	}

}

int main(void)
{
	std::cin >> subin >> sister;

	std::cout << find();
	return 0;
}
