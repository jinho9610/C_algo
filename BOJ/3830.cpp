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

const int MAX = 100000 + 1;
int n, m, Root[MAX];
int dist[MAX];

int update(int x)
{
    if (Root[x] == x)
        return x;
    int R = update(Root[x]);  // 현재 내가 속한 집합의 루트노드
    dist[x] += dist[Root[x]]; // 노드 x에서 x의 루트 노드까지의 거리 갱신

    return Root[x] = R;
}

void merge(int a, int b, int diff)
{
    int aRoot = Root[a]; // a의 루트
    int bRoot = Root[b]; // b의 루트

    if (aRoot == bRoot)
        return; // 이미 같은 집단에 속한 상태면 뭐 할 것 없음

    int new_dist_a = dist[a] + diff;
    int old_dist_b = dist[b];
    Root[bRoot] = aRoot;                   // a와 b를 같은 집단으로 연결
    dist[bRoot] = new_dist_a - old_dist_b; // b에서
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        for (int i = 1; i <= n; i++) // 부모 초기화
        {
            Root[i] = i;
            dist[i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            char c;
            int a, b, w;
            cin >> c >> a >> b;
            update(a);
            update(b); // 부모 찾으면서 Root는 물론, dist 배열도 갱신

            if (c == '!')
            {
                cin >> w;
                merge(a, b, w);
            }
            else
            {
                if (Root[a] == Root[b])
                    cout << dist[b] - dist[a] << '\n';
                else
                    cout << "UNKNOWN\n";
            }
        }
    }

    return 0;
}