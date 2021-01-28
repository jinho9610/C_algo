// 풀이에 사용된 알고리즘:

#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <vector>

using namespace std;

typedef long long ll;

int k, gear[5][9];
vector<pair<int, int>> commands;

void cw(int g) // g는 기어 번호
{
    int tmp = gear[g][8]; // 마지막꺼
    for (int i = 8; i > 1; i--)
        gear[g][i] = gear[g][i - 1];
    gear[g][1] = tmp;
}

void ccw(int g) // 반시계 방향 기어 회전
{
    int tmp = gear[g][1];
    for (int i = 1; i < 8; i++)
        gear[g][i] = gear[g][i + 1];
    gear[g][8] = tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < 5; i++) // 톱니 정보 입력받기
    {
        for (int j = 1; j < 9; j++)
        {
            char c;
            cin >> c;
            gear[i][j] = c - '0';
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b; // b가 1이면 cw, -1이면 ccw
        cin >> a >> b;
        commands.push_back({a, b});
    }

    for (auto command : commands)
    {
        int target_gear = command.first;
        int dir = command.second; // 회전 방향

        //기어간 관계 파악 필요
        // 1번 기어의 3번 톱니 - 2번 기어의 7번 톱니
        // 2번 기어의 3번 톱니 - 3번 기어의 7번 톱니
        // 3번 기어의 3번 톱니 - 4번 기어의 7번 톱니
        bool g1 = false, g2 = false, g3 = false, g4 = false;

        if (target_gear == 1)
        {
            if (dir == 1)
            {
                g1 = true;
                if (gear[1][3] != gear[2][7])
                {
                    g2 = true;
                    if (gear[2][3] != gear[3][7])
                    {
                        g3 = true;
                        if (gear[3][3] != gear[4][7])
                            g4 = true;
                    }
                }

                if (g1)
                    cw(1);
                if (g2)
                    ccw(2);
                if (g3)
                    cw(3);
                if (g4)
                    ccw(4);
            }

            else
            {
                g1 = true;
                if (gear[1][3] != gear[2][7])
                {
                    g2 = true;
                    if (gear[2][3] != gear[3][7])
                    {
                        g3 = true;
                        if (gear[3][3] != gear[4][7])
                            g4 = true;
                    }
                }
                if (g1)
                    ccw(1);
                if (g2)
                    cw(2);
                if (g3)
                    ccw(3);
                if (g4)
                    cw(4);
            }
        }

        else if (target_gear == 2)
        {
            if (dir == 1)
            {
                g2 = true;
                if (gear[1][3] != gear[2][7])
                    g1 = true;
                if (gear[2][3] != gear[3][7])
                {
                    g3 = true;
                    if (gear[3][3] != gear[4][7])
                        g4 = true;
                }
                if (g1)
                    ccw(1);
                if (g2)
                    cw(2);
                if (g3)
                    ccw(3);
                if (g4)
                    cw(4);
            }
            else
            {
                g2 = true;
                if (gear[1][3] != gear[2][7])
                    g1 = true;
                if (gear[2][3] != gear[3][7])
                {
                    g3 = true;
                    if (gear[3][3] != gear[4][7])
                        g4 = true;
                }
                if (g1)
                    cw(1);
                if (g2)
                    ccw(2);
                if (g3)
                    cw(3);
                if (g4)
                    ccw(4);
            }
        }

        else if (target_gear == 3)
        {
            if (dir == 1)
            {
                g3 = true;
                if (gear[3][3] != gear[4][7])
                    g4 = true;
                if (gear[2][3] != gear[3][7])
                {
                    g2 = true;
                    if (gear[1][3] != gear[2][7])
                        g1 = true;
                }
                if (g1)
                    cw(1);
                if (g2)
                    ccw(2);
                if (g3)
                    cw(3);
                if (g4)
                    ccw(4);
            }
            else
            {
                g3 = true;
                if (gear[3][3] != gear[4][7])
                    g4 = true;
                if (gear[2][3] != gear[3][7])
                {
                    g2 = true;
                    if (gear[1][3] != gear[2][7])
                        g1 = true;
                }
                if (g1)
                    ccw(1);
                if (g2)
                    cw(2);
                if (g3)
                    ccw(3);
                if (g4)
                    cw(4);
            }
        }

        else if (target_gear == 4)
        {
            if (dir == 1)
            {
                g4 = true;
                if (gear[3][3] != gear[4][7])
                {
                    g3 = true;
                    if (gear[2][3] != gear[3][7])
                    {
                        g2 = true;
                        if (gear[1][3] != gear[2][7])
                            g1 = true;
                    }
                }
                if (g1)
                    ccw(1);
                if (g2)
                    cw(2);
                if (g3)
                    ccw(3);
                if (g4)
                    cw(4);
            }

            else
            {
                g4 = true;
                if (gear[3][3] != gear[4][7])
                {
                    g3 = true;
                    if (gear[2][3] != gear[3][7])
                    {
                        g2 = true;
                        if (gear[1][3] != gear[2][7])
                            g1 = true;
                    }
                }
                if (g1)
                    cw(1);
                if (g2)
                    ccw(2);
                if (g3)
                    cw(3);
                if (g4)
                    ccw(4);
            }
        }
    }

    int result = 0;
    if (gear[1][1] == 0)
        result += 0;
    else
        result += 1;
    if (gear[2][1] == 0)
        result += 0;
    else
        result += 2;
    if (gear[3][1] == 0)
        result += 0;
    else
        result += 4;
    if (gear[4][1] == 0)
        result += 0;
    else
        result += 8;

    cout << result << '\n';

    return 0;
}