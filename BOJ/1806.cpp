#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int n, s;
int arr[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int min_val = 987654321;

    for (int start = 0; start < n; start++)
    {
        int sum = 0;
        for (int end = start; end < n; end++)
        {
            sum += arr[end];
            if (sum >= s)
            {
                min_val = min(min_val, end - start + 1);
                break;
            }
        }
    }

    if (min_val == 987654321)
        cout << 0 << endl;
    else
        cout << min_val << endl;

    return 0;
}