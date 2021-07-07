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

int tc, n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;

    for (int t = 1; t <= tc; t++) // testcase
    {
        vector<int> nums(10);

        for (int i = 0; i < 10; i++)
            cin >> nums[i];

        sort(nums.begin(), nums.end());

        nums.erase(nums.begin());
        nums.erase(nums.end() - 1);

        ll sum = 0;
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
            sum += *iter;

        cout << '#' << t << ' ' << round((double)sum / 8) << '\n';
    }

    return 0;
}