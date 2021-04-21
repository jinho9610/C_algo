#include <iostream>
#include <deque>
#include <cmath>
#include <cstring>

using namespace std;

#define endl '\n'
#define CLOCK 1
#define N 0
#define S 1

int k, visited[5];
deque<int> gears[5];

// 실제로 몇번 톱니바퀴를 어떤 방향으로 회전하는 함수
void rotation(int g, int dir)
{
    if (dir == CLOCK) // 시계 방향 회전일 경우
    {
        //7번 값이 0번으로 와야해
        int tmp = gears[g].back();
        gears[g].pop_back();
        gears[g].push_front(tmp);
    }
    else
    {
        // 0번 값이 7번으로 가야해
        int tmp = gears[g].front();
        gears[g].pop_front();
        gears[g].push_back(tmp);
    }
}

// 어떤 톱니바퀴들이 회전해야하는지 파악하는 함수
void check(int g, int dir)
{
    visited[g] = true;
    int left_g = g - 1, right_g = g + 1;

    if (left_g >= 1 && gears[left_g][2] != gears[g][6] && !visited[left_g])
        check(left_g, -dir);
    if (right_g <= 4 && gears[g][2] != gears[right_g][6] && !visited[right_g])
        check(right_g, -dir);

    rotation(g, dir);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    // 톱니바퀴 상태 입력 받기
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char x;
            cin >> x;
            gears[i].push_back(x - '0');
        }
    }
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int g, dir;
        cin >> g >> dir;

        memset(visited, 0x00, sizeof(visited));
        check(g, dir);
    }

    int result = 0;
    for (int i = 1; i <= 4; i++)
        result += (gears[i][0] * pow(2, i - 1));

    cout << result << '\n';

    return 0;
}