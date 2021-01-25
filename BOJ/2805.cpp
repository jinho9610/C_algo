#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>

using namespace std;

int n, m, h;
vector<int> woods;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        woods.push_back(a);
    }

    sort(woods.begin(), woods.end(), greater<int>());

    int start = 0, end = woods[0];

    while (start <= end)
    {
        int mid = (start + end) / 2;

        long len = 0;
        for (int i = 0; i < woods.size(); i++)
        {
            if (woods[i] > mid)
            {
                len += (woods[i] - mid);
            }
        } // len을 높이를 mid로 설정하여 나무를 잘랐을 때 가져갈 수 있는 나무 토막들 길이

        if (len == m)
        {
            h = mid;
            break;
        }

        if (len > m)
        {
            //토막들이 m보다 길다면
            start = mid + 1;
            h = mid;
        }
        else if (len < m)
        {
            end = mid - 1;
        }
    }

    cout << h << endl;

    return 0;
}