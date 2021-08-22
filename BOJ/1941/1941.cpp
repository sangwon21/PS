#include <iostream>

char array[5][5];
bool map[5][5];
bool visited[25];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int answer = 0;
// cnt를 전역으로 두지 않으면 dfs로 7을 만들 수 없는 경우가 있다
int cnt = 1;

void checkComponent(bool visit[][5], int y, int x)
{
    if (cnt == 7)
    {
        answer++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (0 <= ny && ny < 5 && 0 <= nx && nx < 5)
        {
            if (map[ny][nx] == true && visit[ny][nx] == false)
            {
                visit[ny][nx] = true;
                cnt++;
                checkComponent(visit, ny, nx);
            }
        }
    }
}

void checkPosition()
{
    bool visit[5][5];
    cnt = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            visit[i][j] = false;
        }
    }

    for (int i = 0; i < 25; i++)
    {
        if (visited[i] == true)
        {
            int y = i / 5;
            int x = i % 5;

            visit[y][x] = true;
            checkComponent(visit, y, x);
            break;
        }
    }
}

// 임도연 -> 'Y'
// 이다솜 -> 'S'
void dfs(int doyeon, int count, int target)
{
    if (count >= 7)
    {
        if (doyeon >= 4)
        {
            return;
        }
        checkPosition();
        return;
    }
    else
    {
        for (int i = target; i < 25; i++)
        {

            if (visited[i] == false)
            {
                map[i / 5][i % 5] = true;
                visited[i] = true;
                if (array[i / 5][i % 5] == 'Y')
                {
                    dfs(doyeon + 1, count + 1, i + 1);
                }
                else
                {
                    dfs(doyeon, count + 1, i + 1);
                }
                map[i / 5][i % 5] = false;
                visited[i] = false;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cin >> array[i][j];
        }
    }

    dfs(0, 0, 0);

    std::cout << answer << '\n';
    return 0;
}