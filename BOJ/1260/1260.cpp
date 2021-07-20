#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

int N, M, V;

std::vector<int> list[1001];
bool check[1001];

void dfs(int index)
{
	check[index] = true;
	printf("%d ", index);
	for (int i = 0; i < list[index].size(); i++)
	{
		int next = list[index][i];
		if (check[next] == false)
		{
			dfs(next);
		}
	}
}

void bfs(int index)
{
	std::queue<int> q;
	memset(check, false, sizeof(check));

	q.push(index);
	check[index] = true;
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		printf("%d ", current);
		for (int i = 0; i < list[current].size(); i++)
		{
			int next = list[current][i];
			if (check[next] == false)
			{
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	std::cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		list[a].push_back(b);
		list[b].push_back(a);
	}

	for (int i = 1; i < N; i++)
	{
		std::sort(list[i].begin(), list[i].end());
	}

	dfs(V);
	printf("\n");
	bfs(V);

	return 0;
}