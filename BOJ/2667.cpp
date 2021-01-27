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

int n, arr[26][26], visited[26][26], complex = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(pair<int, int> p1)
{
    int cnt = 0;
    queue<pair<int, int>> q;

    visited[p1.first][p1.second] = complex;
    q.push(p1);

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        cnt++; // 단지 내 집 수

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (!visited[nx][ny] && arr[nx][ny] == 1) // 방문한적없고, 집이 있다면
            {
                visited[nx][ny] = true; // 방문처리
                q.push({nx, ny});
            }
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }

    int cnt;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                complex++;
                cnt = bfs({i, j});
                ans.push_back(cnt);
            }
        }
    }

    cout << complex << '\n';

    sort(ans.begin(), ans.end());

    for (auto iter = ans.begin(); iter != ans.end(); iter++)
        cout << *iter << '\n';

    return 0;
}