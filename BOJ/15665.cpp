#include <iostream>
#include <algorithm>

int ans[10];
int num[10];
int cnt[10];


int N, M;

void go(int idx)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
		{
			std::cout << num[ans[i]] << ' ';
		}
		std::cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		ans[idx] = i;
		go(idx + 1);
	}
}
int main(void)
{
	std::cin >> N >> M;
	int tmp[10];

	for (int i = 0; i < N; i++)
	{
		std::cin >> tmp[i];
	}

	std::sort(tmp, tmp + N);

	int c = 1;
	int k = 0;
	int x = tmp[0];

	for (int i = 0; i < N; i++)
	{
		if (tmp[i] == x)
		{
			c += 1;
		}
		else
		{
			num[k] = x;
			cnt[k] = c;
			x = tmp[i];
			k += 1;
			c = 1;
		}
	}
	num[k] = x;
	cnt[k] = c;
	N = k + 1;

	go(0);

	return 0;
}