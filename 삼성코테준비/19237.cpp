#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

struct SHARK
{
	int x, y, dir;
	bool isInmap;
};

typedef pair<int, int> pii;
typedef long long ll;

int n, m, k, arr[21][21];
int prior[401][5][4]; // 상어 번호, 현재 바라보는 방향
pii scents[21][21]; // 현재 맵에 남겨져있는 냄새 정보
SHARK shark[401];

int dx[] = { 0, -1, 1, 0, 0 }; // 상하좌우
int dy[] = { 0, 0, 0, -1, 1 };

bool isInside(int x, int y)
{
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

// 냄새 감소 함수
void decrease_scents()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (scents[i][j].second > 0)
			{
				scents[i][j].second--;
				if (scents[i][j].second == 0) // 냄새가 하나도 안남아있으면
					scents[i][j].first = 0; // 냄새를 남긴 상어 번호도 없애버림(0으로 만듦) (유효한 상어 번호는 1이상이니까)
			}
		}
	}
}

// 맵 안에 남아있는 상어 수 체크하는 함수
int left_sharks()
{
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		if (shark[i].isInmap == true)
			cnt++;
	}
	return cnt;
}

void print_scents()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << scents[i][j].second << ' ';
		}
		cout << endl;
	}
}

void move_sharks()
{
	vector<int> tmp[21][21];

	for (int i = 1; i <= m; i++) // m마리의 상어에 대해서
	{
		if (shark[i].isInmap == false) // 맵 안에 있지 않은 상어에 대해서는 고려 x
			continue;

		int x = shark[i].x, y = shark[i].y; // 상어 위치
		int staring_dir = shark[i].dir; // 현재 바라보는 방향
		
		bool flag1 = false;

		// 1. 인접 네 지역 파악
		for (int heading : prior[i][staring_dir]) // 탐색 순서
		{
			int nx = x + dx[heading], ny = y + dy[heading];

			if (isInside(nx, ny) && scents[nx][ny].second == 0) // 냄새가 없는 지역이라면
			{
				// 상어이동 하고 냄새를 (k + 1)만큼 남긴다
				// 모든 상어 이동 후 1씩 감소시킬 것이니까
				tmp[nx][ny].push_back(i);
				shark[i].x = nx, shark[i].y = ny, shark[i].dir = heading;
				flag1 = true; // 첫번째 우선순위 만족한 것
				break;
			}
		}

		if (flag1 == false) // 첫 우선 순위(인접 지역 중 냄새가 없는 곳으로 간다)를 만족하지 못한 경우
		{
			for (int heading : prior[i][staring_dir])
			{
				int nx = x + dx[heading], ny = y + dy[heading];
				if (isInside(nx, ny) && scents[nx][ny].first == i) // 내가 냄새를 남긴 곳이 보인다면
				{
					tmp[nx][ny].push_back(i);
					shark[i].x = nx, shark[i].y = ny, shark[i].dir = heading;
					break;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (tmp[i][j].size() == 0)
				continue;
			
			sort(tmp[i][j].begin(), tmp[i][j].end()); // 오름차순 정렬
			int valid_shark = tmp[i][j][0];
			scents[i][j] = { valid_shark, k + 1 };
			for (int k = 1; k < tmp[i][j].size(); k++)
				shark[tmp[i][j][k]].isInmap = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("s_input.txt", "r", stdin);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int a;
			cin >> a;
			if (a != 0) // a번 상어의 위치
			{
				shark[a] = { i, j, 0, true }; // 방향은 1~4로 이후에 초기화해줄것
				scents[i][j] = { a, k }; // 초기상태에 a 상어가 (i, j)에 존재하고 그 자리에 k만큼 남김
			}
		}
	}
	for (int i = 1; i <= m; i++) // m개의 상어
	{
		int d;
		cin >> d;
		shark[i].dir = d; // 상어의 초기 방향 초기화
	}

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= 4; j++)
			for (int k = 0; k < 4; k++)
				cin >> prior[i][j][k];

	int sec = 0;
	while (true)
	{
		if (left_sharks() == 1 && shark[1].isInmap) // 상어 하나만 남은 경우
			break; // 종료

		if (sec >= 1000 && left_sharks() != 1)
		{
			cout << -1 << endl;
			return 0;
		}
		// 상어 이동
		move_sharks();
		// 냄새 감소
		decrease_scents();

		sec++;
	}

	cout << sec << endl;
	return 0;
}