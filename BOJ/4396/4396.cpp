#include <iostream>
#include <algorithm>
#include <vector>

char map[10][10];
char answer[10][10];
std::vector<std::pair<int, int>> chosenPositions;
std::vector<std::pair<int, int>> bombPositions;
int length;
const int DIRECTIONS = 8;

int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};

bool isValidPosition(int y, int x)
{
    return 0 <= y && y < length && 0 <= x && x < length;
}

int calculateNearByBombs(int y, int x)
{
    int bomb = 0;

    for (int i = 0; i < DIRECTIONS; i++)
    {
        int targetY = y + dy[i];
        int targetX = x + dx[i];

        if (isValidPosition(targetY, targetX))
        {
            if (map[targetY][targetX] == '*')
            {
                bomb++;
            }
        }
    }

    return bomb;
}

int main()
{
    std::cin >> length;
    bool bombChosen = false;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            std::cin >> map[i][j];
            if (map[i][j] == '*')
            {
                bombPositions.push_back(std::pair<int, int>(i, j));
            }
        }
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            char target;
            std::cin >> target;
            if (target == 'x')
            {
                if (map[i][j] == '*')
                {
                    bombChosen = true;
                    continue;
                }
                else
                {
                    int bombs = calculateNearByBombs(i, j);

                    answer[i][j] = bombs + '0';
                }
            }
            else
            {
                answer[i][j] = '.';
            }
        }
    }

    if (bombChosen)
    {
        for (int i = 0; i < bombPositions.size(); i++)
        {
            std::pair<int, int> bombPosition = bombPositions[i];

            answer[bombPosition.first][bombPosition.second] = '*';
        }
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            std::cout << answer[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}