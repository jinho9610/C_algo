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
string s1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> tc;

    for (int t = 1; t <= tc; t++) // testcase
    {
        cin >> s1;
        string ans = "";

        for (int i = s1.size() - 1; i >= 0; i--)
        {
            char a;
            a = s1[i];

            if (a == 'b')
                ans += 'd';
            else if (a == 'd')
                ans += 'b';
            else if (a == 'p')
                ans += 'q';
            else if (a == 'q')
                ans += 'p';
        }

        cout << '#' << t << ' ' << ans << '\n';
    }

    return 0;
}