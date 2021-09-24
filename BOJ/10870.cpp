/* BOJ 10870 피보나치수5 */
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

int n, fibo[100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    cin >> n;
    fibo[0] = 0, fibo[1] = 1;
    for (int i = 2; i <= n; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    cout << fibo[n] << endl;

    return 0;
}