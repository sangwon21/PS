#include <iostream>
#include <queue>

int S;
int ans;
struct Emoticon
{
	int screen;
	int clipboard;
	int count;
};

bool isValid(int num)
{
	return 1 <= num && num <= 1000;
}

void find()
{
	using namespace std;

	queue<Emoticon> q;
	q.push(Emoticon{ 1, 0, 1 });
	
	while (!q.empty())
	{
		int screen = q.front().screen;
		int clipboard = q.front().clipboard;
		int count = q.front().count;
		q.pop();

		if (screen == S)
		{
			ans = count;
			break;
		}
		if (isValid(screen))
		{
			q.push(Emoticon{ screen, screen, count + 1 });
		}
		if (clipboard != 0 && isValid(screen + clipboard))
		{
			q.push(Emoticon{ screen + clipboard, clipboard, count + 1 });
		}
		if (isValid(screen - 1))
		{
			q.push(Emoticon{ screen - 1, clipboard, count + 1 });	
		}

	}


}
int main(void)
{
	std::cin >> S;
	
	find();

	std::cout << ans - 1 << '\n';
	return 0;
}