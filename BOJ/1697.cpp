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

int n, k, visited[100001];

int bfs()
{
    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < 3; i++)
        {

            int nxt;
            if (i == 0)
                nxt = now - 1;
            else if (i == 1)
                nxt = now + 1;
            else
                nxt = now * 2;

            if (nxt == k)
                return visited[now];

            if (-1 < nxt && nxt < 100001 && !visited[nxt])
            {
                visited[nxt] = visited[now] + 1;
                q.push(nxt);
            }
        }
    }

    return visited[k] - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    if (n == k)
    {
        cout << 0 << endl;
        return 0;
    }

    int result = bfs();

    cout << result << '\n';

    return 0;
}