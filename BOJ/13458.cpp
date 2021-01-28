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

int n, tests[1000001], b, c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> tests[i];

    cin >> b >> c;

    ll result = 0;

    for (int i = 1; i <= n; i++)
    {
        result++;

        if (tests[i] > b)
        {
            if ((tests[i] - b) % c == 0)
                result += (tests[i] - b) / c;
            else
                result = result + (int)((tests[i] - b) / c) + 1;
        }

        else // 부감독이 필요하지 않음
            continue;
    }

    cout << result << '\n';

    return 0;
}