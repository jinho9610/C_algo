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

int n, m, h;
bool ladder[31][11];
int ans = -1;
bool found = false;

bool check_ladder()
{
    bool flag = true;
    for (int i = 1; i <= n; i++) // 몇번째 세로줄인지
    {
        int cur = i;                 // 현재 세로선에서 출발
        for (int j = 1; j <= h; j++) // 높이
        {
            if (ladder[j][cur])                     // 오른쪽 세로선으로 사다리가 있다면
                cur++;                              // 오른쪽 세로선으로 이동
            else if (cur > 1 && ladder[j][cur - 1]) // 왼쪽 세로선으로 사다리가 있다면
                cur--;                              // 왼쪽 세로선으로 이동
        }

        if (cur == i)
            flag = true;
        else
        {
            flag = false;
            break;
        }
    }

    return flag;
}

void dfs(int height, int cnt, int target)
{
    if (found)
        return;

    if (cnt == target) // 목표한 개수만큼 설치했다면
    {
        if (check_ladder())
        {
            found = true;
            ans = cnt;
        }
        return;
    }

    for (int j = height; j <= h; j++)
    {
        for (int i = 1; i < n; i++)
        {
            if (!ladder[j][i] && !ladder[j][i - 1] && !ladder[j][i + 1]) // 설치하지 않았다면
            {
                ladder[j][i] = true;     // 설치
                dfs(j, cnt + 1, target); // 더 설치
                ladder[j][i] = false;    // 제거
            }
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> n >> m >> h;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true; // 높이 a에서 b와 b+1을 연결하는 사다리가 있다
    }

    for (int i = 0; i <= 3; i++)
    {
        dfs(1, 0, i);
        if (found)
        {
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans << endl;

    return 0;
}