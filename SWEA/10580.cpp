// 풀이에 사용된 알고리즘: 완전탐색

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

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> tc;

    for (int t = 1; t <= tc; t++) // testcase
    {
        vector<pair<int, int>> info;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            info.push_back(make_pair(a, b));
        }

        sort(info.begin(), info.end(), cmp);

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (info[i].second > info[j].second)
                    cnt++;
            }
        }
        cout << '#' << t << ' ' << cnt << '\n';
    }

    return 0;
}