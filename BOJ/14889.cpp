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

int n, arr[21][21], selected[21];
int result = 1e9;

void dfs(int idx, int cnt)
{
    if (cnt == n / 2)
    {
        vector<int> start;
        vector<int> link;
        int t1 = 0, t2 = 0;

        for (int i = 1; i <= n; i++) // start 팀과 link 팀으로 나누기
        {
            if (selected[i])
                start.push_back(i);
            else
                link.push_back(i);
        }

        for (int i = 1; i <= n / 2; i++) // 점수 계산, 배열의 idx는 1부터 시작하지만 벡터의 idx는 0부터 시작함에 주의
        {
            for (int j = 1; j <= n / 2; j++)
            {
                t1 += arr[start[i - 1]][start[j - 1]];
                t2 += arr[link[i - 1]][link[j - 1]];
            } // 각 팀의 능력치의 합 계산
        }

        result = min(abs(t1 - t2), result);

        return;
    }

    for (int i = idx; i <= n; i++)
    {
        if (!selected[i])
        {
            selected[i] = true;
            dfs(i, cnt + 1);
            selected[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    dfs(1, 0);

    cout << result << '\n';

    return 0;
}