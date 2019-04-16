#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

std::vector<int> list[20001];
int colors[20001];

int testcases;
int V, E;

void go(int index, int color)
{
	if (colors[index])
	{
		return;
	}
	colors[index] = color;
	for (int i = 0; i < list[index].size(); i++)
	{
		if (colors[list[index][i]] == 0)
		{
			go(list[index][i], 3 - color);
		}
	}
}


int main(void)
{
	scanf("%d", &testcases);

	while (testcases--)
	{
		scanf("%d %d", &V, &E);
		for (int i = 1; i <= V; i++)
		{
			list[i].clear();
			colors[i] = 0;
		}
		for (int i = 0; i < E; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			list[a].push_back(b);
			list[b].push_back(a);
		}

		for (int i = 1; i <= V; i++)
		{
			if (colors[i] == 0)
			{
				go(i, 1);
			}
		}

		bool okay = true;

		for (int i = 1; i <= V; i++)
		{
			for (int j = 0; j < list[i].size(); j++)
			{
				if (colors[i] == colors[list[i][j]])
				{
					okay = false;
					break;
				}

			}
		}

		if (okay)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}