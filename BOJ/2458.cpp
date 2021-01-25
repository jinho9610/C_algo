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

int n, m;
vector<vector<int>> height_asc;  // 나보다 큰 애들에 대한 정보
vector<vector<int>> height_desc; // 나보다 작은 애들에 대한 정보
bool visited[501];
int cnt_desc = -1;
int cnt_asc = -1;

void dfs_asc(int node)
{
    // 1. 체크인
    visited[node] = true;
    cnt_asc++;

    // 2. 목표 달성
    // 완전 탐색할거야

    // 3. 갈수있는 곳 순회
    for (int i = 0; i < height_asc[node].size(); i++) // 현재 학생보다 큰 학생들 탐색
    {
        int new_node = height_asc[node][i];
        if (!visited[new_node]) // 4. 갈 수 있냐
            dfs_asc(new_node);  // 5. 간다
    }

    // 6. 체크아웃
    //visited[node] = false;
}

void dfs_desc(int node)
{
    // 1. 체크인
    visited[node] = true;
    cnt_desc++;

    // 2. 목표 달성
    // 완전 탐색할거야

    // 3. 갈수있는 곳 순회
    for (int i = 0; i < height_desc[node].size(); i++) // 현재 학생보다 작은 학생들 탐색
    {
        int new_node = height_desc[node][i];
        if (!visited[new_node]) // 4. 갈 수 있냐 // 방문한 적이 없는 경우만
            dfs_desc(new_node); // 5. 간다
    }

    // 6. 체크아웃
    //visited[node] = false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    height_asc.resize(n + 1);
    height_desc.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        height_asc[a].push_back(b);  // 나보다 키 큰 애들에 대한 정보
        height_desc[b].push_back(a); // 나보다 키 작은 애들에 대한 정보 // 간선의 방향을 바꿔서 인접 리스트 작성한 것
    }

    ll result = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt_asc = -1, cnt_desc = -1; // 초기화
        memset(visited, false, sizeof(visited));
        dfs_asc(i);
        memset(visited, false, sizeof(visited));
        dfs_desc(i);
        if (cnt_asc + cnt_desc == n - 1)
            result++;
    }

    cout << result << '\n';

    return 0;
}