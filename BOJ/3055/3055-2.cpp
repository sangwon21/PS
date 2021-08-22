#include <iostream>
#include <queue>
#include <vector>

char map[51][51];
bool visited[51][51];
bool hogVisited[51][51];
int row;
int column;
std::pair<int, int> hedgehog;
std::queue<std::pair<int, int>> hogPositions;
std::queue<std::pair<int, int>> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int y, int x)
{
    return 0 <= y && y < row && 0 <= x && x < column;
}

bool isNotStone(int y, int x)
{
    return map[y][x] != 'X';
}

bool isNotDen(int y, int x)
{
    return map[y][x] != 'D';
}

bool waterSafety(int y, int x)
{
    //if (map[y][x] == '*')
    //{
    //	return false;
    //}

    //for (int i = 0; i < 4; i++)
    //{
    //	int newY = y + dy[i];
    //	int newX = x + dx[i];

    //	if (isValid(newY, newX))
    //	{
    //		if (map[newY][newX] == '*')
    //		{
    //			return false;
    //		}
    //	}
    //}

    //return true;
    return map[y][x] != '*';
}

// 물 * 돌 X 비버 D 고슴도치 S

int main()
{
    std::cin >> row >> column;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cin >> map[i][j];

            if (map[i][j] == 'S')
            {
                hogPositions.push(std::pair<int, int>(i, j));
                hogVisited[i][j] = true;
            }
            else if (map[i][j] == '*')
            {
                q.push(std::pair<int, int>(i, j));
                visited[i][j] = true;
            }
        }
    }

    bool found = false;
    int turn = 1;

    while (hogPositions.empty() == false)
    {
        // 실패 상황
        if (found)
        {
            break;
        }

        int waterSize = q.size();
        for (int i = 0; i < waterSize; i++)
        {
            std::pair<int, int> target = q.front();
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int newY = target.first + dy[j];
                int newX = target.second + dx[j];

                if (isValid(newY, newX) && isNotStone(newY, newX) && isNotDen(newY, newX) && visited[newY][newX] == false)
                {
                    visited[newY][newX] = true;
                    map[newY][newX] = '*';
                    q.push(std::pair<int, int>(newY, newX));
                }
            }
        }

        int posSize = hogPositions.size();
        for (int i = 0; i < posSize; i++)
        {
            std::pair<int, int> target = hogPositions.front();
            hogPositions.pop();

            for (int j = 0; j < 4; j++)
            {
                int newY = target.first + dy[j];
                int newX = target.second + dx[j];

                if (isValid(newY, newX))
                {
                    if (map[newY][newX] == 'D')
                    {
                        found = true;
                        std::cout << turn << '\n';
                        return 0;
                    }
                    if (isNotStone(newY, newX) && waterSafety(newY, newX) && hogVisited[newY][newX] == false)
                    {
                        hogVisited[newY][newX] = true;
                        hogPositions.push(std::pair<int, int>(newY, newX));
                        map[newY][newX] = 'S';
                    }
                }
            }
        }

        turn++;
    }

    if (found == false)
    {
        std::cout << "KAKTUS" << std::endl;
    }

    return 0;
}