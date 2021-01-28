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

int n, cnt, cols[16];

bool promising(int x)
{
    int k = 1;

    while (k < x)
    {
        if (cols[k] == cols[x] || abs(cols[x] - cols[k]) == abs(x - k))
        {
            return false;
        }
        k++;
    }
    return true;
}

void chess(int x)
{
    if (promising(x))
    {
        if (x == n)
            cnt++;
        else
        {
            for (int i = 1; i <= n; i++)
            {
                cols[x + 1] = i;
                chess(x + 1);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    chess(0);

    cout << cnt << '\n';

    return 0;
}