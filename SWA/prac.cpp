#include <iostream>
using namespace std;
const int MAX = 987654321;
int film[13][20];
int temp[13][20];
int D, W, K;
bool is_passed()
{
    for (int i = 0; i < W; i++)
    {
        bool flag = false;
        int cnt = 1;
        for (int j = 0; j < D - 1; j++)
        {
            if (film[j][i] == film[j + 1][i])
                cnt++;
            else
            {
                cnt = 1;
            }
            if (cnt == K)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return false;
    }
    return true;
}
void insert_chemical(int row, int che)
{
    for (int i = 0; i < W; i++)
    {
        film[row][i] = che;
    }
}
int solve(int row, int cnt)
{
    if (row == D)
    {
        if (is_passed())
            return cnt;
        else
            return K;
    }
    for (int i = 0; i < W; i++)
    {
        temp[row][i] = film[row][i];
    }
    int ret = MAX;
    ret = min(ret, solve(row + 1, cnt));
    insert_chemical(row, 0);
    if (cnt + 1 < ret)
        ret = min(ret, solve(row + 1, cnt + 1));
    insert_chemical(row, 1);
    if (cnt + 1 < ret)
        ret = min(ret, solve(row + 1, cnt + 1));
    for (int i = 0; i < W; i++)
    {
        film[row][i] = temp[row][i];
    }
    return ret;
}
void input()
{
    cin >> D >> W >> K;
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> film[i][j];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        input();
        cout << '#' << t << ' ' << solve(0, 0) << '\n';
    }
    return 0;
}
