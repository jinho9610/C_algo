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

int m, n, arr[1001][1001];
queue<pair<int, int>> q;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isInside(int x, int y)
{
    return 0 < x && x <= n && 0 < y && y <= m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    bool f = true; // 모든 토마토가 익어있는지

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                q.push({i, j}); // 토마토는 모두 큐에 넣은 상태로 시작
            else if (arr[i][j] == 0)
                f = false; // 모든 토마토가 익어 있지는 않다.
        }
    }

    // 모든 토마토가 익어있는 경우
    if (f)
    {
        cout << 0 << '\n';
        return 0;
    }

    int cnt = -1; // 마지막에 한 번 헛도니까 -1로 시작
    while (!q.empty())
    {
        cnt++; // 날짜 카운트
        int size = q.size();

        while (size--)
        {
            int x = q.front().first, y = q.front().second; // 현재 꺼낸 노드의 x, y
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];

                if (isInside(nx, ny) && arr[nx][ny] == 0) // 맵 안에 있고, 익지 않은 토마토인 경우에만
                {
                    arr[nx][ny] = 1; // 익은 토마토로 변경
                    q.push({nx, ny});
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 0)
            {
                cout << -1 << "\n"; // 토마토가 모두 익지는 못하는 상황
                return 0;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}