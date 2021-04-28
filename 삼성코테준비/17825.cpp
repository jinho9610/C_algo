////어디로 갈지를 지정하는 문제

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

#define endl '\n'
#define INF 1e9
#define PATH1LIMIT 3
#define PATH2LIMIT 2
#define PATH3LIMIT 3
#define PATH4LIMIT 3

using namespace std;

typedef pair<int, int> pii;

int arr[10], mal[4], map[35], turn[35], check[35], score[35];
int ans;

void dfs(int cnt, int sum)
{
	if (cnt == 10) // 주사위 열번 다 돌림
	{
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int cur = mal[i]; // 현재 말의 위치
		int len = arr[cnt]; // 움직여야하는 칸 수
		int next = cur;
		if (turn[cur] > 0) // 방향 전환해야하는 경우 경로를 변경한다.
		{
			next = turn[cur];
			len -= 1;
		}

		// 실제 이동
		for (int m = 0; m < len; m++)
			next = map[next];

		if (next != 21 && check[next])
			continue; // 도착칸도 아닌데 다른 말이 있으면 다른 말 움직여

		check[next] = true;
		check[cur] = false;
		mal[i] = next;
		dfs(cnt + 1, sum + score[next]);
		mal[i] = cur;
		check[cur] = true;
		check[next] = false;


	}
}
int main()
{
	freopen("s_input.txt", "r", stdin);

	for (int i = 0; i < 21; i++) // map[a]=b 는 a번 발판을 밟으면 다음은 b번으로 간다는 것을 의미
		map[i] = i + 1;
	map[21] = 21;
	for (int i = 22; i < 27; i++)
		map[i] = i + 1;
	map[28] = 29, map[29] = 30, map[30] = 25;
	map[31] = 32, map[32] = 25, map[27] = 20;

	turn[5] = 22, turn[10] = 31, turn[15] = 28, turn[25] = 26;

	for (int i = 0; i < 21; i++)
		score[i] = i * 2; // i번 발판을 밟았을 때의 점수

	score[22] = 13, score[23] = 16, score[24] = 19;
	score[31] = 22, score[32] = 24, score[28] = 28;
	score[29] = 27, score[30] = 26, score[25] = 25;
	score[26] = 30, score[27] = 35;

	for (int i = 0; i < 10; i++)
		cin >> arr[i];

	dfs(0, 0);

	cout << ans << endl;

	return 0;
}