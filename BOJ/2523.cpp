/* BOJ 2623 음악프로그램 */
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

int n, m, inDegrees[1001];
vector<vector<int>> edges;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m;
    edges.resize(n + 1);

    int cnt, start, dest;
    while (m--)
    {
        cin >> cnt;
        bool flag = false;
        while (cnt--)
        {
            if (!flag)
                cin >> start, flag = true;
            else
            {
                cin >> dest;
                inDegrees[dest]++;
                edges[start].push_back(dest);
                start = dest;
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (inDegrees[i] == 0)
            q.push(i);

    vector<int> ans;
    int connected_cnt = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        connected_cnt++;

        for (int next : edges[cur])
        {
            if (--inDegrees[next] == 0)
                q.push(next);
        }
    }

    if (connected_cnt != n)
        cout << 0 << endl;
    else
        for (int a : ans)
            cout << a << endl;
    return 0;
}