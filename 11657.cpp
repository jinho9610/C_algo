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
bool isMinus; // 음의 싸이클이 발생하였는 지 확인
const int INF = 1e9;
int n, m;

vector<pair<int, int>> edges[501];
vector<ll> dist;

void Bellman_Ford(int node)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INF)
                continue; // 방문한 적, 혹은 변화가 전혀 없다면 다음 노드 및 간선 탐색

            for (auto edge : edges[i])
            {
                int next_node = edge.first;
                int distance = edge.second;

                if (distance + dist[i] < dist[next_node])
                {
                    dist[next_node] = distance + dist[i];
                    if (k == n - 1)
                        isMinus = true; // 마지막에도 업데이트 발생하면 마이너스사이클 존재
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    dist.resize(n + 1, INF);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c)); // a---->b로 가는 비용 c
    }

    dist[1] = 0; // 시작지점은 방문한 것으로 체크하고 시작
    Bellman_Ford(0);

    if (isMinus) // 음의 싸이클 발생하면 무한히 과거로 갈 수 있음
        cout << -1 << '\n';

    else // 음의 싸이클이 발생하지 않는 경우에는 dist 배열 출력
    {
        for (int i = 2; i <= n; i++)
        {
            if (dist[i] == INF)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }

    return 0;
}