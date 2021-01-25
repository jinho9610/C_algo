#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <vector>
#include <unordered_set>

using namespace std;

typedef long long ll;

int node_cnt = 0;
int edge_cnt = 0;
unordered_set<int> nodes;

int main()
{
    // 트리는 간선의 개수가 항상 노드의 개수 + 1이다.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    int case_cnt = 1;
    while (1)
    {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        if (a == 0 && b == 0) // 지금부터 트리 여부 확인
        {
            if (edge_cnt == 0 || nodes.size() == edge_cnt + 1)
            {
                cout << "Case " << case_cnt << " is a tree.\n";
            }
            else
            {
                cout << "Case " << case_cnt << " is not a tree.\n";
            }
            nodes.clear();
            edge_cnt = 0;
            case_cnt++;
        }
        else // 노드와 간선 정보 입력
        {
            nodes.insert(a);
            nodes.insert(b);
            edge_cnt++;
        }
    }

    return 0;
}