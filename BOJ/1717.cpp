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

int n, m, pr[1000010];

int find_parent(int a)
{
    if (a == pr[a])
        return a;

    return pr[a] = find_parent(pr[a]);
}

void union_parent(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);

    pr[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        pr[i] = i;

    for (int i = 0; i < m; i++)
    {
        int cmd, a, b;
        cin >> cmd >> a >> b;

        if (cmd == 0)
        {
            union_parent(a, b);
        }
        else if (cmd == 1)
        {
            if (find_parent(a) == find_parent(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}