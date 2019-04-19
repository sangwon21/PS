#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int N;
int maxNum = -1000000001;
int minNum = 1000000001;
int numbers[11];
// +,-,*,/
int symbols[4];

int putSymbols[11];

void calculateResult()
{
	int sum = numbers[0];
	for (int i = 1; i < N ; i++)
	{
		switch (putSymbols[i -1])
		{
		case 0:
			sum = sum + numbers[i];
			break;
		case 1:
			sum = sum - numbers[i];
			break;
		case 2:
			sum = sum * numbers[i];
			break;
		case 3:
			sum = sum / numbers[i];
			break;
		}
	}

	if (sum > maxNum)
		maxNum = sum;
	if (sum < minNum)
		minNum = sum;
}
void go(int idx)
{
	if (idx == N - 1)
	{
		calculateResult();
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (symbols[i] > 0)
		{
			symbols[i] -= 1;
			putSymbols[idx] = i;
			go(idx + 1);
			symbols[i] += 1;
		}
	}

}
int main(void)
{

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &numbers[i]);
	}
	
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &symbols[i]);
	}

	go(0);

	printf("%d\n", maxNum);
	printf("%d\n", minNum);

	return 0;
}