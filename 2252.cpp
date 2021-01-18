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

int n, m, indegree[32010]; // 노드 별 "들어오는 간선 수"
vector<int> adj[32010];    // 인접리스트
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        // a->b
        adj[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        //queue에 넣는다.
        if (indegree[i] == 0)
            q.push(i); // 0인 애들만 다 넣기
    }
    // 모아놓은것을 하나씩 q에서 뽑으면서 출력하고
    // 연결된 것들의 간선은 하나씩 줄여준다.
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' '; // 작은 순으로 출력
        // 연결된 간선을 하나씩 줄인다.
        for (int i = 0; i < adj[cur].size(); i++)
        {
            indegree[adj[cur][i]]--;
            if (indegree[adj[cur][i]] == 0)
                q.push(adj[cur][i]);
        }
    }
    return 0;
}