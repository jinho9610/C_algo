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

int n, a, b, m, visited[101]; // rel은 촌수를 나타내는 변수
vector<int> adj[101];

void dfs(int x, int rel)
{
    // 1.체크인
    visited[x] = rel;

    // 2. 목적지 도달했는지

    // 3. 연결된 곳 순회 -> 즉 부모 또는 자식
    for (int i = 0; i < adj[x].size(); i++)
    {
        int nxt = adj[x][i];

        if (visited[nxt] == -1) // 4. 갈 수 있는가 // 방문한적이 없는 경우
            dfs(nxt, rel + 1);  // 5. 간다
    }

    // 6. 체크아웃(필요하면) -> 불필요
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(visited, 0xff, sizeof(visited));

    cin >> n >> a >> b >> m;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(a, 0);

    if (visited[b] != -1)
        cout << visited[b] << '\n';

    else
        cout << -1 << '\n';

    return 0;
}