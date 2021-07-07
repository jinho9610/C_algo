// 풀이에 사용된 알고리즘:

#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;

int tc, n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;

    for (int t = 1; t <= tc; t++) // testcase
    {
        cin >> n >> m;
        bitset<32> bs(m);
        string bits = bs.to_string();

        int idx = bits.size() - 1;
        bool yesorno = true;
        for (int i = 0; i < n; i++)
        {
            if (bits[idx] == '0') // 꺼진 비트 발견하면 탈출
            {
                yesorno = false;
                break;
            }
            idx--;
        }

        if (yesorno)
            cout << '#' << t << ' ' << "ON\n";
        else
            cout << '#' << t << ' ' << "OFF\n";
    }

    return 0;
}