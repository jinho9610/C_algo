#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int n, m, k;
vector<ll> nums;
vector<ll> tree;
vector<pair<int, pair<int, int>>> operations;

ll makeTree(int node, int left, int right)
{
    if (left == right) // 리프 노드라면
    {
        if (left <= n)
            return tree[node] = nums[left];
        else
            return tree[node] = 0;
    }

    int mid = (left + right) / 2;
    tree[node] = makeTree(node * 2, left, mid);
    tree[node] += makeTree(node * 2 + 1, mid + 1, right);

    return tree[node];
}

ll query(int node, int left, int right, int qLeft, int qRight) // 구간에 대한 쿼리
{
    if (qRight < left || right < qLeft) // 쿼리 밖이라면
    {
        return 0;
    }
    else if (qLeft <= left && right <= qRight) // 현재 노드의 구간이 쿼리 내부라면
    {
        int mid = (left + right) / 2;
        return query(node * 2, left, mid, qLeft, qRight) +
               query(node * 2 + 1, mid + 1, right, qLeft, qRight);
    }
}

void update(int node, int left, int right, int index, ll diff)
{
    if (left <= index && index <= right)
    {
        tree[node] += diff;
        if (left != right)
        {
            int mid = (left + right) / 2;
            update(node * 2, left, mid, index, diff);
            update(node * 2 + 1, mid + 1, right, index, diff);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) // 대상 숫자
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    for (int i = 0; i < m + k; i++) // 명령
    {
        int a, b, c;
        cin >> a >> b >> c;
        operations.push_back(make_pair(a, make_pair(b, c)));
    }

    int s = 1;
    while (s < n)
        s *= 2;

    tree.resize(s * 2, 0);
    makeTree(1, 0, s - 1);

    for (int i = 0; i < tree.size(); i++)
        cout << tree[i] << ' ';

    return 0;
}