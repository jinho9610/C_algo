// 풀이에 사용된 알고리즘: dijkstra || union-find

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
int n, m, pr[501], dist[501], plan[501];
vector<pair<int, int>> edges[501];

int find_parent(int x)
{
    if (pr[x] == x)
        return pr[x];
    else
        return pr[x] = find_parent(pr[x]);
}

void union_parent(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);

    pr[a] = b;
}

int main() // 사이클이 발생하는 지를 확인하는 알고리즘
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        pr[i] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            if (a == 1)
                union_parent(i, j);
        }
    }

    for (int i = 0; i < m; i++)
        plan[i];

    bool cycle = true;
    for (int i = 1; i < m; i++)
    {
        if (find_parent(plan[i]) != find_parent(plan[i - 1]))
        {
            cycle = false;
            break;
        }
    }

    if (cycle)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

// 다익스트라를 사용한 완전탐색 + 그리디 방식
// void dijkstra(int start)
// {
//     priority_queue<pair<int, int>> pq;
//     pq.push({0, start});
//     dist[start] = 0;

//     while (!pq.empty())
//     {
//         int now = pq.top().second;
//         int distance = -pq.top().first;
//         pq.pop();

//         if (dist[now] < distance)
//             continue;

//         for (auto edge : edges[now])
//         {
//             int next = edge.first;
//             int cost = edge.second + distance;

//             if (dist[next] > cost)
//             {
//                 dist[next] = cost;
//                 pq.push({-cost, next});
//             }
//         }
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     freopen("input.txt", "r", stdin);

//     cin >> n >> m;

//     for (int i = 0; i < n; i++) // 양방향 간선 정보 입력받기
//     {
//         int a, b;
//         cin >> a >> b;
//         edges[a].push_back({b, 1});
//         edges[b].push_back({a, 1});
//     }

//     for (int i = 0; i < m; i++) // 여행 계획 입력 받기
//         cin >> plan[i];

//     bool flag = true;
//     for (int i = 1; i < m; i++)
//     {
//         fill(dist, dist + 501, INF); // dist 배열 초기화
//         dijkstra(plan[i]);
//         if (dist[plan[i - 1]] == INF)
//         {
//             flag = false;
//             break;
//         }
//     }

//     if (flag)
//         cout << "YES" << endl;
//     else
//         cout << "NO" << endl;

//     return 0;
// }