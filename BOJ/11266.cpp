// 풀이에 사용된 알고리즘: DFS

#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int v, e, visited_order[10010], num = 1; // 점, 간선, 방문순서
ll cnt = 0;
vector<int> adj[100010];
set<int> ans;

int dfs(int cur, bool isRoot)
{
    visited_order[cur] = num++;

    int ret = visited_order[cur]; // 현재 노드에서 올라갈 수 있는 최대한 작은 번호

    int CT = 0; //자식 트리의 수

    for (auto child : adj[cur])
    {
        if (visited_order[child] != 0) // 이미 방문한 적이 있다면
            ret = min(ret, visited_order[child]);
        else
        {
            //방문한 적이 없는 경우 자식 트리 생성
            CT++;
            int Ctree = dfs(child, false);              // 자식 노드는 root 노드일 수는 없으니 false
            if (Ctree >= visited_order[cur] && !isRoot) // 현재 노드가 root가 아니고, 자식 노드들이 내 위(나보다 작은 번호의 노드)로 가지 못하면
                ans.insert(cur);

            ret = min(ret, Ctree); // 올라갈 수 있는 가장 높은 노드(번호가 가장 작은 노드) 갱신
        }
    }
    if (isRoot && CT >= 2) // 내가 root 노드인데 자식 트리가 2개인 경우에는 root를 지우면, 단절된 두 개의 트리 생성
        ans.insert(cur);

    return ret;
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
    num = 1;
    for (int i = 1; i <= v; i++)
    {
        if (!visited_order[i])
            if (visited_order[i] == 0)
                dfs(i, true);
    }

    // 출력

    cout << ans.size() << '\n';
    for (auto e : ans)
        cout << e << ' ';
    cout << '\n';

    return 0;
}