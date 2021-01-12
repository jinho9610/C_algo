#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int t, n, m;
int A[1001], B[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> B[i];

    vector<int> sub_a;
    vector<int> sub_b;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += A[j];
            sub_a.push_back(sum);
        }
    } // 부 배열의 합 구하기

    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = i; j < m; j++)
        {
            sum += B[j];
            sub_b.push_back(sum);
        }
    } // 부 배열의 합 구하기

    sort(sub_a.begin(), sub_a.end());
    sort(sub_b.begin(), sub_b.end()); // 오름차순 정렬

    int a = sub_a.size(), b = sub_b.size();
    int a_p = 0, b_p = b - 1; // sub_a의 왼쪽끝과 sub_b의 오른쪽 끝에서 시작하기 위한 인덱스 할당, sum은 t와 비교됨
    long cnt = 0;             // 최종적으로 출력할 답

    while (1)
    {
        long long sum = sub_a[a_p] + sub_b[b_p]; // 현재 sum 구하고

        if (sum > t)
            b_p--;
        else if (sum < t)
            a_p++;
        else // sum이 t와 같다면
        {    // 동일한 값을 내는 경우의 수를 구해서 cnt에 더함
            long a_cnt = 1, b_cnt = 1;
            while (a_p + 1 < a && sub_a[a_p] == sub_a[a_p + 1])
            {
                a_cnt++;
                a_p++;
            }
            while (b_p > 0 && sub_b[b_p] == sub_b[b_p - 1])
            {
                b_cnt++;
                b_p--;
            }
            cnt += a_cnt * b_cnt;
            a_p++;
            b_p--;
        }

        if (a_p >= a || b_p < 0)
        {
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}