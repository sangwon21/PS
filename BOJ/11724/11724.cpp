#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int N, M;

std::vector<int> list[1001];
bool check[1001];

void go(int index)
{
	if (check[index])
	{
		return;
	}
	check[index] = true;
	
	for (int i = 0; i < list[index].size(); i++)
	{
		if (check[list[index][i]] == false)
		{
			go(list[index][i]);
		}
	}
}

int main(void)
{
	
	int cnt = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		list[a].push_back(b);
		list[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		if (check[i] == false)
		{
			go(i);
			cnt += 1;
		}
	}

	printf("%d\n", cnt);

	return 0;
}