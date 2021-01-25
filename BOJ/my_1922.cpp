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

int n, m, pr[1001];
ll result_cost;
vector<pair<int, pair<int, int>>> edges;

bool cmp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
{
    return p1.second.second < p2.second.second;
}

int find_parent(int x)
{
    if (x == pr[x])
        return pr[x];

    return pr[x] = find_parent(pr[x]);
}

void union_parent(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);

    pr[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        pr[i] = i;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(make_pair(a, make_pair(b, c)));
    }

    sort(edges.begin(), edges.end(), cmp); // 비용을 기준으로 오름차순 정렬

    for (int i = 0; i < edges.size(); i++)
    {
        pair<int, pair<int, int>> edge = edges[i];
        int a = edge.first, b = edge.second.first, c = edge.second.second;

        // 사이클발생하면 신장트리에 포함 x
        if (find_parent(a) != find_parent(b))
        {
            union_parent(a, b);
            result_cost += c;
        }
    }

    cout << result_cost << '\n';

    return 0;
}