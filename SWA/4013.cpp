#include <iostream>
#include <deque>
#include <cstring>
#include <cmath>

#define endl '\n'

using namespace std;

typedef long long ll;

int T, k;
bool visited[5];
deque<int> gears[5];

//실제 회전
void rotate(int g, int d)
{
    if (d == 1) //  시계방향
    {
        int tmp = gears[g].back();
        gears[g].pop_back();
        gears[g].push_front(tmp);
    }
    else if (d == -1) // 반시계방향
    {
        int tmp = gears[g].front();
        gears[g].pop_front();
        gears[g].push_back(tmp);
    }
}
// 회전필요한 톱니 파악
void check(int g, int d)
{
    visited[g] = true;

    int l = g - 1, r = g + 1;

    if (l > 0 && gears[l][2] != gears[g][6] && !visited[l])
        check(l, -d);

    if (r < 5 && gears[g][2] != gears[r][6] && !visited[r])
        check(r, -d);

    rotate(g, d);
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> k;

        for (int i = 1; i <= 4; i++)
        {
            gears[i].clear();
            for (int j = 0; j < 8; j++)
            {
                int v;
                cin >> v;
                gears[i].push_back(v);
            }
        }

        for (int i = 0; i < k; i++)
        {
            memset(visited, 0x00, sizeof(visited));

            int num, dir;
            cin >> num >> dir;

            check(num, dir);
        }

        int result = 0;
        for (int i = 1; i <= 4; i++)
            result += gears[i][0] * pow(2, i - 1);

        cout << "#" << t << " " << result << '\n';
    }

    return 0;
}