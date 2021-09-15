/* BOJ 20040 사이클 게임 */
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

int n, m, arr[500001], p[500001];

int find_parent(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = find_parent(p[x]);
}

void union_parent(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);

    if (a < b)
        p[b] = a;
    else
        p[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        p[i] = i;

    for (int i = 1; i <= m; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;

        int p1_parent = find_parent(p1);
        int p2_parent = find_parent(p2);

        if (p1_parent == p2_parent) // 사이클 발생
        {
            cout << i << endl;
            return 0;
        }

        union_parent(p1, p2);
    }

    cout << 0 << endl;

    return 0;
}