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

int n, w[11][11], visited[11], selected[11];
int result = 1e9, start;

void dfs(int cur, int cnt, int cost)
{
    if (cnt == n && cur == start) // n개 도시 모두 방문했으면
    {
        result = min(result, cost);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (w[cur][i] == 0)
            continue;

        if (!visited[i])
        {
            visited[i] = true;
            dfs(i, cnt + 1, cost + w[cur][i]);
            visited[i] = false;
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
            cin >> w[i][j];

    for (int i = 1; i <= n; i++)
    {
        start = i;
        dfs(i, 0, 0);
    }

    cout << result << endl;

    return 0;
}