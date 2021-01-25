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

int n, q;

vector<ll> nums;
vector<ll> tree;

ll makeTree(int node, int left, int right)
{
    if (left == right)
    {
        if (left <= n)
            return tree[node] = nums[left];
        else
            return 0;
    }
    else
    {
        int mid = (left + right) / 2;
        tree[node] = makeTree(node * 2, left, mid) + makeTree(node * 2 + 1, mid + 1, right);
        return tree[node];
    }
}

ll query(int node, int left, int right, int qLeft, int qRight)
{
    if (right < qLeft || qRight < left)
        return 0;
    else if (qLeft <= left && right <= qRight)
    {
        return tree[node];
    }

    int mid = (left + right) / 2;
    return query(node * 2, left, mid, qLeft, qRight) + query(node * 2 + 1, mid + 1, right, qLeft, qRight);
}

void update(int node, int left, int right, int idx, ll diff)
{
    if (left <= idx && idx <= right)
    {
        tree[node] += diff;
        if (left != right)
        {
            int mid = (left + right) / 2;
            update(node * 2, left, mid, idx, diff);
            update(node * 2 + 1, mid + 1, right, idx, diff);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    nums.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    int s = 1;
    while (s < n)
        s *= 2;

    tree.resize(2 * s);

    makeTree(1, 1, s);
    // for (int i = 0; i < tree.size(); i++)
    //     cout << tree[i] << ' ';

    vector<ll> ans;
    for (int i = 0; i < q; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x < y)
            ans.push_back(query(1, 1, s, x, y));
        else
            ans.push_back(query(1, 1, s, y, x));
        update(1, 1, s, a, b - nums[a]);
        nums[a] = b;
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';

    return 0;
}