/* BOJ 14916 거스름돈 */
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

#define endl '\n'

typedef long long ll;

int mon;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> mon;

    for (int i = mon / 5; i >= 0; --i)
    {
        if ((mon - i * 5) % 2 == 0)
        {
            cout << i + (mon - i * 5) / 2 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}