/* BOJ 11005 진법 변환 2 */
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

int n, b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> b;
    string str = "";

    while (n != 0)
    {
        int r = n % b;

        if (r >= 10)
            str = (char)(r + 'A' - 10) + str;
        else
            str = (char)(r + '0') + str;

        n /= b;
    }

    cout << str << endl;

    return 0;
}