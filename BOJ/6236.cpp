/* BOJ 6236 용돈 관리 */
/* 이진탐색, 파라메트릭 서치 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string.h>

#define endl '\n'

using namespace std;

typedef long long ll;

const int INF = 1e9;
int money[100001], n, m, ans = INF;

bool check_answer(int k)
{
	// 1~n번째 날까지, 인출 시 k만큼할 때 살아갈 수 있는 지
	int balance = 0; // 잔고
	int cnt = 0; // 인출 횟수
	int need = 0; // i번째 날을 살아가기 위해 필요한 예산
	for (int i = 1; i <= n; i++)
	{
		need = money[i];
		if (need > k) // 인출할 수 있는 금액보다 큰 예산이 필요하면 생활 불가
			return false;

		if (balance < need) // 필요 예산보다 잔고가 조금 적다면
		{
			balance = k - need; // 모든 돈을 넣고 k만큼 인출 후 소비
			cnt++; // 인출 횟수 증가
		}
		else // 잔고로 충분히 살아갈 수 있다면
			balance -= need; // 인출 없이 소비
	}
	return cnt <= m;
}

void binary_search(int left, int right)
{
	if (left > right)
		return; // 탐색 종료

	int k = (left + right) / 2;

	if (check_answer(k)) // k로도 살아갈 수 있다면
		ans = min(k, ans), binary_search(left, k - 1); // 조금 더 적은 금액을 인출하는 방식으로도 살아갈 수 있는 지 파악
	else // 한 번 인출 시 k로는 못 살아간다면, k 증가
		binary_search(k + 1, right);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> money[i];

	binary_search(0, INF);
	cout << ans << endl;

	return 0;
}
