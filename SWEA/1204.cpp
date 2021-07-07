// 풀이에 사용된 알고리즘: 별거 없이 파이썬에서의 딕셔너리 대신에 c++의 map을 사용하였음

#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int tc, n;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second != p2.second)
        return p1.second > p2.second;
    else
        return p1.first > p2.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;

    for (int t = 1; t <= tc; t++) // testcase
    {
        int dum;
        cin >> dum;

        map<int, int, greater<int>> m;
        //cout << "size " << m.size() << endl;
        for (int i = 1; i <= 1000; i++)
        {
            int score;
            cin >> score;
            m[score]++;
        }

        vector<pair<int, int>> tmpv(m.begin(), m.end());
        sort(tmpv.begin(), tmpv.end(), cmp);

        cout << '#' << t << " " << tmpv[0].first << '\n';
    }

    return 0;
}