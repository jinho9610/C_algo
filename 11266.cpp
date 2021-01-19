// 풀이에 사용된 알고리즘: 단절점 찾기. 제대로 풀이 불가

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

int v, e, visited_order[10010], num = 1; // 점, 간선, 방문순서
ll cnt = 0;
vector<int> adj[10010];
bool ans[10010]; // 단절점인지 아닌지

int dfs(int parent, int cur, bool isRoot)
{
    int min_visited_order = 20000; // 내 자식들이 만날 수 있는 점 중에서 가장 작은 점
    int childCnt = 0;

    visited_order[cur] = num++; // 어떤 점을 몇번째로 방문했는 지 표시

    for (int i = 0; i < adj[cur].size(); i++)
    {
        int nxt = adj[cur][i];
        if (nxt == parent)
            continue;

        if (visited_order[nxt])
            min_visited_order = min(min_visited_order, visited_order[nxt]);
        else
        {
            min_visited_order = min(min_visited_order, dfs(cur, nxt, false));
            if (isRoot != true && dfs(cur, nxt, false) >= visited_order[cur])
                ans[cur] = true;
            childCnt++;
        }
    }

    // 리프노드면, 단절점처리 x
    if (adj[cur].size() == 1)
        return visited_order[cur];

    if (isRoot)
    {
        if (childCnt >= 2)
        {
            ans[cur] = true;
        }
    }
    else
    {
        if (min_visited_order >= visited_order[cur])
        {
            ans[cur] = true;
        }
    }

    return min(min_visited_order, visited_order[cur]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // 무방향 간선
    }

    //단절점 찾고
    for (int i = 1; i <= v; i++)
    {
        if (!visited_order[i])
            dfs(0, i, true);
    }

    // 출력

    cout << cnt << '\n';
    for (int i = 1; i <= v; i++)
    {
        if (ans[i])
            cout << i << ' ';
    }

    return 0;
}