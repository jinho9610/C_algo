#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;

int n;

int main()
{
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    vector<int> C(n);
    vector<int> D(n);

    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        A[i] = a, B[i] = b, C[i] = c, D[i] = d;
    }

    // 공간 절약을 위해서 굳이 A, B의 합을 미리 새로운 벡터에 담아둘 필요는 없다.
    vector<ll> CD; // C 배열과 D 배열에서 나올 수 있는 모든 "합의 경우"를 담은 배열
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(CD.begin(), CD.end()); // CD 오름차순 정렬

    ll cnt = 0; // 카운트용 변수는 습관적으로 long long으로 선언하자.
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            ll target = A[i] + B[j];
            vector<ll>::iterator low = lower_bound(CD.begin(), CD.end(), -target);
            if (target + (*low) == 0)
            {
                vector<ll>::iterator high = upper_bound(CD.begin(), CD.end(), -target);
                cnt += (high - low);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}