#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;

ll x, y, z;

// int main()
// {
//     cin >> x >> y;
//     z = (y * 100) / x; // 현재 승률
//     if (z >= 99)
//     {
//         cout << -1 << endl;
//         return 0;
//     }

//     ll dest = z + 1; // 목표 승률

//     //p 이상인 정수를 출력해야함. p가 이미 정수라면 p출력하고, p가 정수가 아니면 int(p)+1 출력
//     if ((dest * x - 100 * y) % (100 - dest) == 0)
//         cout << (dest * x - 100 * y) / (100 - dest) << endl;
//     else
//         cout << (dest * x - 100 * y) / (100 - dest) + 1 << endl;

//     return 0;
// }

/*모범답안*/
//파라메트릭 서치를 이용해서 upper bound구하기
int main()
{
    cin >> x >> y;
    z = 100 * y / x;

    int low = 0, high = 1000000001;

    while (low < high)
    {
        int mid = (low + high) / 2;
        ll temp = 100*(y+mid)/(x+mid));

        if (temp <= z)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return 0;
}