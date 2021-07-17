#include <iostream>
#include <map>
#include <algorithm>

int bingo[5][5];
const int LENGTH = 5;
const int CHECKED = -1;
std::map<int, std::pair<int, int>> bingoMap;

int checkBingo()
{
    int bingoLine = 0;

    // row
    for (int i = 0; i < LENGTH; i++)
    {
        bool lineBingo = false;
        for (int j = 0; j < LENGTH; j++)
        {
            if (bingo[i][j] != CHECKED)
            {
                break;
            }
            if (j == LENGTH - 1)
            {
                lineBingo = true;
            }
        }

        if (lineBingo)
        {
            bingoLine++;
        }
    }

    // column
    for (int i = 0; i < LENGTH; i++)
    {
        bool lineBingo = false;
        for (int j = 0; j < LENGTH; j++)
        {
            if (bingo[j][i] != CHECKED)
            {
                break;
            }
            if (j == LENGTH - 1)
            {
                lineBingo = true;
            }
        }

        if (lineBingo)
        {
            bingoLine++;
        }
    }

    // left diagonal
    for (int i = 0; i < 5; i++)
    {
        if (bingo[i][i] != CHECKED)
        {
            break;
        }
        if (i == 4)
        {
            bingoLine++;
        }
    }

    // right diagonal
    for (int i = 0; i < 5; i++)
    {
        if (bingo[i][4 - i] != CHECKED)
        {
            break;
        }
        if (i == 4)
        {
            bingoLine++;
        }
    }

    return bingoLine;
}

int main()
{
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            std::cin >> bingo[i][j];
            bingoMap[bingo[i][j]] = std::pair<int, int>(i, j);
        }
    }

    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            int called;
            std::cin >> called;
            std::pair<int, int> p = bingoMap[called];
            bingo[p.first][p.second] = CHECKED;

            int bingoLine = checkBingo();
            if (bingoLine >= 3)
            {
                printf("%d\n", (i * 1) * 5 + (j + 1));
                return 0;
            }
        }
    }

    return 0;
}