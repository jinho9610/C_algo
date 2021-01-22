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
#include <map>
#include <unordered_map>

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

    cin >> tc;

    for (int t = 1; t <= tc; t++) // testcase
    {
        cin >> n;
        int cur_dist = 1e9, cnt = 0, a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;

            if (abs(a) < cur_dist)
            {
                cur_dist = abs(a);
                cnt = 1;
            }
            else if (abs(a) == cur_dist)
                cnt++;
        }
        cout << '#' << t << ' ' << cur_dist << ' ' << cnt << '\n';
    }

    return 0;
}