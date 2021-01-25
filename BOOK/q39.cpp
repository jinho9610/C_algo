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

const int INF = 1e9;
int tc, n, arr[126][126], dist[126][126];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct cmp
{
    bool operator()(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
    {
        return p1.first > p2.first;
    }
};

bool isInside(int x, int y)
{
    return x > 0 && x <= n && y > 0 && y <= n;
}

int calcCost(int x, int y)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq; // 첫번째 원소를 기준으로한느 최소힙
    dist[x][y] = arr[x][y];
    pq.push(make_pair(arr[x][y], make_pair(x, y)));

    while (!pq.empty())
    {
        int cur_x = pq.top().second.first, cur_y = pq.top().second.second;
        int distance = pq.top().first;
        pq.pop();

        if (dist[cur_x][cur_y] < distance)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int next_x = cur_x + dx[i], next_y = cur_y + dy[i];

            if (!isInside(next_x, next_y))
                continue;

            int cost = distance + arr[next_x][next_y];

            if (cost < dist[next_x][next_y])
            {
                dist[next_x][next_y] = cost;
                pq.push(make_pair(cost, make_pair(next_x, next_y)));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = INF;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> arr[i][j];

        calcCost(1, 1);

        cout << dist[n][n] << '\n';
    }

    return 0;
}