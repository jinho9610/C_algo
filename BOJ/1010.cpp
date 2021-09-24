/* BOJ 1010 다리 놓기 */
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

int T, n, m, combi[31][31];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> T;

    combi[0][0] = 1;
    for (int i = 1; i <= 30; i++)
    {
        for (int j = 0; j <= 30; j++)
        {
            if (j == 0 || i == j)
                combi[i][j] = 1;
            else
                combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
        }
    }

    while (T--)
    {
        cin >> n >> m;
        cout << combi[m][n] << endl;
    }

    return 0;
}