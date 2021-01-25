// 풀이에 사용된 알고리즘: union-find - 아이디어를 떠올리기가 어려움

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

int g, p, gi, pr[100001];

int find_parent(int x)
{
    if (pr[x] == x)
        return pr[x];
    else
        return pr[x] = find_parent(pr[x]);
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

    freopen("input.txt", "r", stdin);

    cin >> g >> p;

    for (int i = 0; i <= g; i++)
        pr[i] = i;

    int cnt = 0;
    for (int i = 0; i < p; i++)
    {
        cin >> gi;
        int cur_p = find_parent(gi);
        if (cur_p == 0)
            break;
        else
        {
            union_parent(cur_p, cur_p - 1);
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}