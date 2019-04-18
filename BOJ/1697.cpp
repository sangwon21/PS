#include <iostream>
#include <queue>

int subin, sister;
int dist[200001];
bool check[200001];

bool isSafe(int  num) {
	return 0 <= num && num <= 100000;
}

void find()
{
	using namespace std;

	queue<int> q;
	q.push(subin);
	dist[subin] = 1;
	check[subin] = true;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		if (current == sister)
		{
			break;
		}

		if (isSafe(current * 2) && check[current * 2] == false)
		{
			dist[current * 2] = dist[current] + 1;
			check[current * 2] = true;
			q.push(current * 2);
		}
		if (isSafe(current - 1) && check[current - 1] == false)
		{
			dist[current - 1] = dist[current] + 1;
			check[current - 1] = true;
			q.push(current - 1);
		}
		if (isSafe(current + 1) && check[current + 1] == false)
		{
			dist[current + 1] = dist[current] + 1;
			check[current + 1] = true;
			q.push(current + 1);
		}
	}
}
int main(void)
{
	std::cin >> subin >> sister;

	find();

	std::cout << dist[sister] - 1 << '\n';
	return 0;
}