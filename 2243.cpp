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

int n, a, b;
ll c;
const int MAX = 1000001;

vector<ll> tree;

ll makeTree(int node, int left, int right)
{
    if (left == right)
    {
        if (left <= n)
            return tree[node] = candy[node];
        else
            return tree[node] = 0;
    }

    int mid = (left + right) / 2;
    return tree[node] = makeTree(node * 2, left, mid) + makeTree(node * 2 + 1, mid + 1, right);
}

ll query(int node, int left, int right, int target)
{                      // 카운트만을 이용해서 실제 데이터가 무엇인지 찾을 때 많이 사용되는 방식
    if (left == right) // 리프노드 도달한 경우
        return left;

    else
    {
        int mid = (left + right) / 2;
        if (left >= target) // 왼쪽으로 가야하는 경우
            query(node * 2, left, mid, target);

        else
            query(node * 2 + 1, mid + 1, right, target - tree[node * 2]); // 자기 왼쪽 자식의 값만큼을 빼줘야함
    }
}

void update(int node, int left, int right, int idx, ll diff)
{
    if (left <= idx && idx <= right)
    {
        tree[node] += diff;
        if (left != right)
        {
            int mid = (left + right) / 2;
            update(node, left, mid, idx, diff);
            update(node, mid + 1, right, idx, diff);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int s = 1;
    while (s < MAX)
        s *= 2;
    tree.resize(s * 2, 0);
    makeTree(1, 1, s);

    vector<ll> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> a;

        if (a == 1)
        {
            cin >> b;
            ll flavor = query(1, 0, MAX - 1, b);
            ans.push_back(flavor);
            update(1, 0, MAX - 1, flavor, -1);
        }
        else
        {
            cin >> b >> c;
            update(1, 0, MAX - 1, b, c);
        }
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';

    return 0;
}