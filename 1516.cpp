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

int n, build_time[510], answer[501], indegree[501], before_max[510];
vector<int> adj[510];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> build_time[i];
        while (true)
        {
            int a;
            cin >> a;
            if (a == -1)
                break;

            adj[a].push_back(i);
            indegree[i]++;
        }
    }

    //위상정렬 통해서
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i); // 들어오는 간선이 없는 노드부터 시작
    }
    // 각각의 건물이 지어지는 최소시간 ==> answer
    while (!q.empty())
    {
        int cur = q.front(); 
        q.pop();
        // cur 처리... 이미 before_max는 어떤 값이 들어있는 상태임이 자명
        answer[cur] = before_max[cur] + build_time[cur];
        // 다음 건물 처리
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int nxt = adj[cur][i];
            --indegree[nxt];
            if (before_max[nxt] < answer[cur])
                before_max[nxt] = answer[cur];
            if (indegree[nxt] == 0)
                q.push(nxt);
        }
    }

    // 출력
    for (int i = 1; i <= n; i++)
        cout << answer[i] << '\n';

    return 0;
}