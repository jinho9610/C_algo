#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int arr[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int start = 0, result = 0;
    for (int start = 0; start < n; start++)
    {
        int sum = 0;
        for (int end = start; end < n; end++)
        {
            sum += arr[end];
            if (sum > m)
                break;
            if (sum == m)
            {
                result++;
                break;
            }
        }
    }

    cout << result << endl;

    return 0;
}