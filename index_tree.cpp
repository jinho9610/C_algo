#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int n;
vector<ll> nums;
vector<ll> tree;

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
    cin >> n;

    nums.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int data;
        cin >> data;
        nums.push_back(data);
    }
    int s = 1;
    while (s < n)
        s *= 2;

    tree.resize(s * 2); // 사이즈 조정을 위해서 벡터로 선언

    makeTree(1, 1, s);

    for (int i = 0; i < tree.size(); i++)
        cout << tree[i] << ' ';
    return 0;
}