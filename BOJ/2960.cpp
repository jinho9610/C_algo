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

int n, k;
vector<bool> arr;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    arr.resize(n + 1, true);

    int result = 0;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i])
        {
            int j = 1;
            while (i * j <= n)
            {
                
                if (arr[i * j])
                {
                    arr[i * j] = false;
                    result++;
                    if (result == k)
                    {
                        cout << i*j << '\n';
                        return 0;
                    }
                }
                j++;
            }
        }
    }

    return 0;
}