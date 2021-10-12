#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int n, m;
vector<int> inDegrees;
vector<int> edges[32001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    inDegrees.resize(n + 1, 0);

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        ++inDegrees[b];
        edges[a].push_back(b);
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (inDegrees[i] == 0)
            q.push(i);

    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (int next : edges[cur])
            if (--inDegrees[next] == 0)
                q.push(next);
    }
    cout << endl;

    return 0;
}