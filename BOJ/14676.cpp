/* BOJ 14676 영우는 사기꾼 */

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

#define endl '\n'

typedef long long ll;

int n, m, k;
int inDegree[100001], requires[100001], constructed[100001];
vector<int> adj[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); // b를 짓기위해서는 a가 필요함을 의미
        requires[b]++;       // b를 짓기위해서 필요한 건물들의 수 계산
    }

    for (int i = 0; i < k; i++)
    {
        int oper, target;
        cin >> oper >> target;

        if (oper == 1) // target을 건설하는 경우
        {
            if (inDegree[target] != requires[target])
            {
                cout << "Lier!" << endl;
                return 0;
            }

            constructed[target]++;

            if (constructed[target] == 1) // 처음 건설한 경우에는
            {
                for (int next : adj[target])
                    inDegree[next]++; // 연관 건물들의 진입 차수 증가
            }
        }
        else // target을 파괴하는 경우
        {
            if (constructed[target] == 0)
            {
                cout << "Lier!" << endl;
                return 0;
            }
            else
            {
                constructed[target]--;
                if (constructed[target] == 0)
                {
                    for (int next : adj[target])
                        inDegree[next]--;
                }
            }
        }
    }

    cout << "King-God-Emperor" << endl;

    return 0;
}