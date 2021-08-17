#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
int arr[11];

void move_idx(int &idx)
{
    idx++;
    if (idx > n)
        idx = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    sort(arr + 1, arr + 1 + n);

    bool flag = true;

    int ans = 1e9;
    while (flag) // 모든 순열들을 탐색하게 되면 flag는 false로 변경되며 while문 중단
    {
        int idx = 1, bucket_weight = 0;
        int cnt = 0, total_weight = 0;
        while (cnt < k)
        {
            if (bucket_weight + arr[idx] > m) // 현재 택배를 담을 경우 바구니 용량 초과하면
            {
                cnt++;        // 현재 바구니에 들어있는 것 옮기고 온다. --> 일한 횟수 1회 증가
                if (cnt == k) // 처음 목표한 횟수만큼 일했다면 stop
                    break;
                else // 바구니 비우고 현재 택배만 담는다.
                    bucket_weight = arr[idx];
            }
            else                           // 현재 택배를 담아도 바구니 용량 초과하지 않는다면
                bucket_weight += arr[idx]; // 단순히 바구니 내 택배 무게만 증가

            total_weight += arr[idx]; // 들은(혹은 옮긴) 택배의 무게 증가

            move_idx(idx); // 다음 레일
        }

        ans = min(ans, total_weight); // 가장 적은 무게를 든 경우의 무게가 정답

        flag = next_permutation(arr + 1, arr + 1 + n); // 새로운 레일 순서 배치
    }

    cout << ans << endl; // 정답 출력

    return 0;
}