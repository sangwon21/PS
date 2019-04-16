#include <iostream>
#include <algorithm>

int N, M;
int arr[10];
int cnt[10];
int num[10];

void go(int idx, int start)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
		{
			std::cout << num[arr[i]] << ' ';
		}
		std::cout << '\n';
		return;
	}
	for (int i = start; i < N; i++)
	{
		arr[idx] = i;
		go(idx + 1, i);
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
	int x = tmp[0];
	int k = 0;

	for (int i = 1; i < N; i++)
	{
		if (tmp[i] == x)
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

	go(0, 0);

	return 0;
}