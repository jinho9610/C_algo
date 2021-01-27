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

using namespace std;

typedef long long ll;

int a, b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    string s2 = to_string(b);

    cout << a * (s2[2] - '0') << endl;
    cout << a * (s2[1] - '0') << endl;
    cout << a * (s2[0] - '0') << endl;
    cout << a * b << endl;

    return 0;
}