#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <ctime>

using namespace std;

const int INF = 1e9;
// 노드 간 비용, dp[i][j]에서 i번째 노드에서, 전체노드들의 방문상태 j를 의미
int n, w[24][24], dp[24][1 << 24]; 

void make_tsp_map(int citynum) // w 배열 초기화하는 함수
{
	for (int i = 0; i < citynum; i++)
		for (int j = 0; j < citynum; j++)
			w[i][j] = min(abs(i - j), citynum - abs(i - j));
}

int tsp(int cur, int state)
{
	if ((state & 1) == 1 && state != (1 << n) - 1) // 탐색이 끝나기전에 시작점(0번째) 비트가 1이 되는 경우
		return INF;
	if (state == (1 << n) - 1) // 탐색이 끝났으면 // 즉 시작 정점 비트를 포함하여 모두 1이 된 경우
		return 0; // v1 -> v1의 비용은 0이므로 0 반환

	int& ret = dp[cur][state]; // 이후 min 값을 저장하기 용이하도록 주소값 가져옴
	if (ret != -1) // 이미 시작점으로부터의 최소 비용이 계산된 노드일 경우
		return ret;

	ret = INF; // 이후 min 연산하기에 적합하도록 큰 값으로 만듦
	for (int i = 0; i < n; i++)
	{
		// 간선이 있고, 현재 state 중에서 비트가 0인 경우에 대해서만 탐색 진행
		if (w[cur][i] > 0 && (state & (1 << i)) == 0)
		{
			// 다음으로 i노드를 방문하는 것이므로 i번째 비트를 1로 만들고, cur -> i로의 비용 추가
			ret = min(ret, tsp(i, state | (1 << i)) + w[cur][i]); // 가장 작은 ret값만 dp에 저장
		}
	}
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	//cin >> n;
	//for (int i = 0; i < n; i++)
	//	for (int j = 0; j < n; j++)
	//		cin >> w[i][j];

	while (true)
	{
		cout << endl;
		memset(dp, 0xff, sizeof(dp)); // dp 배열 모두 -1로 초기화
		cout << "정점 개수: ";
		cin >> n;
		make_tsp_map(n); // w 배열 생성

		cout << "==========w 배열==========" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << w[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';

		memset(dp, 0xff, sizeof(dp)); // dp 배열 모두 -1로 초기화

		clock_t start = clock();
		cout << "찾은 최소 비용 경로: " << tsp(0, 0) << endl;
		clock_t end = clock();
		cout << "소요시간: " << (double)(end - start) << "ms" << endl;
		cout << "\n정보통신공학과 12161719 김진호" << endl;
	}

	return 0;
}