#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000
#define SIZE 50020

vector<vector<int>> ll;
int ac[SIZE][17], depth[SIZE];
int n, m, v, w, u, max_level, temp, child;

void getTree(int current, int parent)
{
    depth[current] = depth[parent] + 1;
    ac[current][0] = parent; // 현재 노드의 직계 조상은 parent
    for (int i = 1; i <= max_level; i++) // max_level = (int)floor(log2(SIZE))
    {
        temp = ac[current][i - 1];
        ac[current][i] = ac[temp][i - 1]; // 내 조부모 부터 = 내 부모의 부모부터 // 동일한 의미이다
    }
    int len = ll[current].size();
    for (int i = 0; i < ll[current].size(); i++)
    {
        int child = ll[current][i];
        if (child != parent)
            getTree(child, current);
    }
}

int main()
{

    return 0;
}