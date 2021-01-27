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

int tc, n;
const int INF = 1e9;
int dist[103][103];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        cin >> n;

        for (int i = 1; i <= n + 2; i++) // dist 초기화
            for (int j = 1; j <= n + 2; j++)
                dist[i][j] = INF;

        vector<pair<int, int>> place;

        for (int i = 0; i < n + 2; i++)
        {
            int x, y;
            cin >> x >> y;
            place.push_back({x, y});
        }

        for (int i = 1; i <= place.size(); i++)
        {
            pair<int, int> p1 = place[i - 1];
            for (int j = 1; j <= place.size(); j++)
            {
                pair<int, int> p2 = place[j - 1];

                int distance = abs(p1.first - p2.first) + abs(p1.second - p2.second);

                if (distance <= 1000)
                {
                    dist[i][j] = 1;
                }
            }
        }

        for (int k = 1; k <= n + 2; k++)
            for (int i = 1; i <= n + 2; i++)
                for (int j = 1; j <= n + 2; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        if (dist[1][n + 2] != INF) // 1번이 상근이 집, n+2가 락페
            cout << "happy\n";
        else
            cout << "sad\n";
    }

    return 0;
}