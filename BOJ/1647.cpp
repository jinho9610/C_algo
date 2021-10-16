/* BOJ 1647 도시 분할 계획 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[100001], n, m;
vector<pair<pair<int, int>, int>> edges;

int find_parent(int x)
{
    if (x == p[x])
        return x;

    return p[x] = find_parent(p[x]);
}

void union_parent(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);

    if (a < b)
        p[b] = a;
    else
        p[a] = b;
}

int main()
{
    cin >> n >> m;

    edges.resize(n + 1);

    for (int i = 1; i <= n; i++)
        p[i] = i;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({{a, b}, c});
    }

    sort(edges.begin(), edges.end(), [](pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) -> bool
         { return p1.second < p2.second; });

    int Max_len = 0, sum = 0;
    for (auto edge : edges)
    {
        int a = edge.first.first;
        int b = edge.first.second;
        int pa = find_parent(a), pb = find_parent(b);

        if (pa == pb)
            continue;

        union_parent(a, b);

        sum += edge.second;
        Max_len = max(Max_len, edge.second);
    }

    cout << sum - Max_len << endl;

    return 0;
}