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
		if (cnt[i] > 0)
		{
			cnt[i] -= 1;
			ans[idx] = i;
			go(idx + 1);
			cnt[i] += 1;
		}
	}
}

int main(void)
{
	int tmp[10];
	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		std::cin >> tmp[i];
	}

	std::sort(tmp, tmp + N);

	int c = 1;
	int k = 0;
	int x = tmp[0];
	for (int i = 1; i < N; i++)
	{
		if (x == tmp[i])
		{
			c += 1;
		}
		else
		{
			num[k] = x;
			cnt[k] = c;
			k += 1;
			x = tmp[i];
			c = 1;
		}
	}

	num[k] = x;
	cnt[k] = c;
	N = k + 1;
	go(0);
	return 0;
}