/* SWEA 1244 최대 상금 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int t, T, swap_cnt, ans = 0;
string num;
bool visited[1000000][11];
// visited[a][b] - 스와핑은 b번 했을 때 a라는 수가 이미 등장했었는 지 확인하기 위한 배열

void dfs(int cnt)
{
	if (cnt == swap_cnt) // 최대 스와핑 횟수만큼 스와핑 진행했으면
	{
		ans = max(ans, stoi(num)); // 더 큰 답으로 갱신
		return; // 되돌아가서 완전 탐색 계속 진행
	}

	for (int i = 0; i < num.length() - 1; i++)
	{
		for (int j = i + 1; j < num.length(); j++)
		{
			swap(num[i], num[j]); // i번째 수와 j번째 수 바꿔치기(이 때 스와핑 횟수는 cnt + 1)이 됨
			if (!visited[stoi(num)][cnt + 1]) // 해당 횟수만큼 스와핑했을 때 등장한 적이 없는 수라면
			{
				visited[stoi(num)][cnt + 1] = true; // 이제 등장한 것으로 체크해주고
				dfs(cnt + 1); // 완전 탐색 계속해서 진행
			}
			swap(num[i], num[j]); // 바꿔치기 했던 수를 원래 자리로 되돌림
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> T;
	for (t = 1; t <= T; t++)
	{
		ans = 0; // 초기화
		memset(visited, 0x00, sizeof(visited)); // 초기화

		cin >> num >> swap_cnt;

		// 완전 탐색 진행
		dfs(0);

		cout << "#" << t << ' ' << ans << endl;
	}

	return 0;
}
