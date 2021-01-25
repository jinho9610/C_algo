// 풀이에 사용된 알고리즘: bfs

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
int n, arr[21][21], dist[21][21], shark_size = 2, shark_x, shark_y;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isInside(int x, int y)
{
    return 0 < x && x <= n && 0 < y && y <= n;
}

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first != p2.first)
        return p1.first > p2.first; // 가장 위에 있는놈
    else
        return p1.second < p2.second; // 가장 왼쪽에 있는 놈
}

void bfs() // 모든 위치까지의 최단거리만 계산하는 bfs
{
    memset(dist, 0xff, sizeof(dist));

    queue<pair<int, int>> q;

    q.push({shark_x, shark_y});
    dist[shark_x][shark_y] = 0;

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 맵 내부이고, 방문한적이 없고, 나보다 같거나 작은 물고기만 지나갈 수 있음
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n)
            {
                if (dist[nx][ny] == -1 && arr[nx][ny] <= shark_size)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

pair<pair<int, int>, int> find_fish() // 먹을 물고기 정하기
{
    int min_dist = INF, x = -1, y = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] != -1 && 1 <= arr[i][j] && arr[i][j] < shark_size)
            {
                if (dist[i][j] < min_dist)
                {
                    x = i, y = j;
                    min_dist = dist[i][j];
                }
            }
        }
    }

    if (min_dist == INF)
        return {{x, y}, min_dist};
    else
        return {{x, y}, min_dist};
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
            cin >> arr[i][j];
            if (arr[i][j] == 9)
            {
                shark_x = i, shark_y = j;
                arr[shark_x][shark_y] = 0;
            }
        }
    }

    int result = 0, ate = 0; // 총 이동 거리(시간), 현재 크기에서 섭취한 물고기 수
    while (true)
    {
        bfs();                                         // 먹을 수 있는 모든 물고기 찾고
        pair<pair<int, int>, int> value = find_fish(); // 가장 가까운 물고기 먹고 나면

        int new_x = value.first.first;
        int new_y = value.first.second;
        int min_dist = value.second;

        if (new_x == -1 && new_y == -1) // 더이상 섭취할 물고기가 없는 경우
            break;

        result += min_dist;

        shark_x = new_x, shark_y = new_y; // 상어 이동
        arr[shark_x][shark_y] = 0;

        ate += 1;

        if (ate >= shark_size)
        {
            shark_size++;
            ate = 0;
        }
    }

    cout << result << endl;

    return 0;
}