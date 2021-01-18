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

#define MAX_NODE 100001
#define swap(a, b) \
    {              \
        int t = a; \
        a = b;     \
        b = t;     \
    }

int depth[MAX_NODE];
int ac[MAX_NODE][20];

vector<int> graph[MAX_NODE];

int max_level, n, m;

// 조상 배열 만드는 과정
void getTree(int here, int parent)
{
    // 현재 노드의 깊이는 부모 노드 깊이 + 1
    depth[here] = depth[parent] + 1;

    // 현재 노드의 첫 번째 조상은 부모 노드
    ac[here][0] = parent;

    // MAX_NODE에 log2를 씌우고 내림하여 max_level 설정
    max_level = (int)floor(log2(MAX_NODE));

    for (int i = 1; i <= max_level; i++)
    {
        // tmp는 현재 노드의 2^(i-1)번째 조상
        /*
            즉, 현재 노드의 2^i 조상은, 현재 노드의 2^i-1 번째 조상의 2^i-1 번째 조상과 동일함을 의미함.
            ex. 현재 노드의 8번째 조상은, 현재 노드의 4번째 조상인 tmp의 4번째 조상과 동일하다.
        */
        int tmp = ac[here][i - 1];
        ac[here][i] = ac[tmp][i - 1];
    }

    int len = graph[here].size(); // 현재 노드와 연결된 모든 자식 노드들에 대해서도 getTree 함수 호출, 즉 위에서 아래로 뻗어나간다.
    for (int i = 0; i < len; i++)
    {
        int there = graph[here][i];
        if (there != parent) // 인접리스트에 들어있는 노드들은 현재 노드의 부모이거나 자식들인데, 자식인경우에 대해서만 코드 돌아감
            getTree(there, here);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    // 양방향 그래프 생성
    for (int i = 1; i < n; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    // root노드번호가 1이고, depth는 0이므로 0번 노드의 depth는 -1로 초기화
    depth[0] = -1;

    getTree(1, 0);

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if (depth[a] != depth[b]) // depth가 다르면 맞춰줘야함
        {
            if (depth[a] > depth[b])
                swap(a, b); // 깊이가 더 큰쪽에 대해서만 코드가 돌아가는 것이 편리하니, 무조건 b의 깊이를 더 크게 a, b를 배치한다

            for (int i = max_level; i >= 0; i--)
            {
                // bd의 2^i번 째 조상이 여전히 a보다 높이 위치한다면 계속해서 b는 내려온다. (최고조상에서 부터)
                if (depth[a] <= depth[ac[b][i]])
                    b = ac[b][i];
            }
        }

        int lca = a; // 공통조상은 a나 b에서 올라가야하니 a로 초기화

        if (a != b) // 서로 같으면 공통조상 찾을 필요없음
        {
            for (int i = max_level; i >= 0; i--)
            {
                if (ac[a][i] != ac[b][i])
                {
                    a = ac[a][i];
                    b = ac[b][i];
                }
                lca = ac[a][i];
            }
        }

        cout << lca << '\n';
    }
    return 0;
}