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

map<string, int> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string wood;
    int cnt = 0;
    while (getline(cin, wood))
    {
        cnt++;
        if (m.find(wood) == m.end())
            m[wood] = 1;
        else
            m[wood]++;
    }

    cout << fixed;
    cout.precision(4);

    for (auto iter = m.begin(); iter != m.end(); iter++)
        cout << iter->first << " " << iter->second / (double)cnt * 100 << '\n';

    return 0;
}