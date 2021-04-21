#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int rotation;
bool visited[4];
deque<int> dq[4];

void gear_turn(int num, int dir)
{
    if (dir == 1)
    {
        int tmp = dq[num].back();
        dq[num].pop_back();
        dq[num].push_front(tmp);
    }
    else
    {
        int tmp = dq[num].front();
        dq[num].pop_front();
        dq[num].push_back(tmp);
    }
}

void gear_check(int num, int dir)
{
    visited[num] = true;

    int prev = num - 1, next = num + 1;

    if (prev >= 0 && !visited[prev])
        if (dq[prev][2] != dq[num][6])
            gear_check(prev, dir * -1);

    if (next < 4 && !visited[next])
        if (dq[next][6] != dq[num][2])
            gear_check(next, dir * -1);

    gear_turn(num, dir);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char a;
            cin >> a;
            dq[i].push_back(a - '0');
        }
    }

    cin >> rotation;

    for (int i = 0; i < rotation; i++)
    {
        memset(visited, 0x00, sizeof(visited));

        int gear_num, gear_dir;
        cin >> gear_num >> gear_dir;

        gear_check(gear_num - 1, gear_dir);
    }

    int res = 0;
    for (int i = 0; i < 4; i++)
        if (dq[i][0] == 1)
            res += pow(2, i);

    cout << res << endl;

    return 0;
}