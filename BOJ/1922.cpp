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

struct Info
{
    int a, b, c;
    Info(int _a, int _b, int _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }
};

int find_parent(int x)
{
    if (pr[x] == x)
        return x;

    pr[x] = find_parent(pr[x]);
    return pr[x];
}

void union_parent(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);

    pr[a] = b;
}

bool cmp(Info i1, Info i2)
{
    return i1.c < i2.c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i <= n; i++) // 부모 정보 초기화
        pr[i] = i;

    vector<Info> edge;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back(Info(a, b, c));
    }

    //간선의 크기 순으로 정렬
    sort(edge.begin(), edge.end(), cmp);

    ll min_cost = 0; // 최소비용
    // union-find 이용해서 트리 구성
    for (int i = 0; i < m; i++)
    {
        // 간선 정보 읽어옴
        int a, b, c;
        a = edge[i].a, b = edge[i].b, c = edge[i].c;
        // 둘이 연결되어 있는지 = 같은 그룹인지
        if (find_parent(a) != find_parent(b))
        {
            union_parent(a, b);
            min_cost += c; // 비용 계산
        }
    }

    cout << min_cost << '\n';

    return 0;
}