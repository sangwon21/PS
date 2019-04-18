#include <iostream>
#include <algorithm>

int N, M;
int arr[10];
int cnt[10];
int num[10];

void go(int idx)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (cnt[i] >= 1)
		{
			cnt[i] -= 1;
			arr[idx] = num[i];
			go(idx + 1);
			cnt[i] += 1;
		}
	}
}
int main(void)
{
	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}

	std::sort(arr, arr + N);

	int c = 1;
	int k = 0;
	int x = arr[0];

	for (int i = 1; i < N; i++)
	{
		if (x == arr[i])
		{
			c += 1;
		}
		else
		{
			num[k] = x;
			cnt[k] = c;
			k += 1;
			x = arr[i];
			c = 1;
		}
	}

	num[k] = x;
	cnt[k] = c;
	N = k + 1;

	go(0);

	return 0;
}