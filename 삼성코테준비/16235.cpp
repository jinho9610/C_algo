#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

#define endl '\n'

typedef pair<int, int> pii;

int n, m, k;
int arr[11][11], energy[11][11];
deque<int> trees[11][11];
vector<int> dead_trees[11][11];
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

bool isInside(int x, int y)
{
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void sort_trees() // 각 칸의 나무들을 나이 오름차순으로 정렬
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sort(trees[i][j].begin(), trees[i][j].end());
}

void print_tree_cnt() // 각 칸에 있는 나무의 수 출력
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << trees[i][j].size() << ' ';
		}
		cout << endl;
	}
}

// 나이만큼 양분 먹고 나이 1증가
void spring()
{
	sort_trees(); // 먼저 각 칸의 나무들을 나이 오름차순으로 정렬
	// 양분못먹는 나무는 다 죽는다
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			bool flag = true;
			unsigned int k = 0;
			for (k = 0; k < trees[i][j].size(); k++)
			{
				int age = trees[i][j][k]; // 나무의 나이
				if (arr[i][j] >= age) // 남아있는 양분이 나이보다 많다면
				{
					arr[i][j] -= age; // 양분 먹고
					trees[i][j][k]++; // 나이 1 증가
				}
				else // k번째 나무부터 더 이상 양분이 충분하지 않다면
				{ // 얘부터는 모두 죽을 것이니 루프 탈출
					flag = false;
					break;
				}
			}
			if (flag == false) // 죽은 나무는 기억한다
			{
				int cur = trees[i][j].size() - 1;
				for (int nk = cur; nk >= k; nk--)
				{
					int age = trees[i][j].back(); // 삭제 대상 나이 파악
					trees[i][j].pop_back(); // 현재 땅에서 삭제하고
					dead_trees[i][j].push_back(age); // 죽은 나무들 명단에 추가
				}
			}
		}
	}
}

void summer()
{
	// 죽은 나무는 양분이 된다
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int dead : dead_trees[i][j])
				arr[i][j] += dead / 2;
		}
	}
	// 양 분이 된 후 죽은 나무 명단 초기화
	memset(dead_trees, 0x00, sizeof(dead_trees));
}

void autumn()
{
	// 나무 번식
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (unsigned int k = 0; k < trees[i][j].size(); k++)
			{
				int age = trees[i][j][k];
				if (age % 5 == 0) // 나이 % 5 == 0인 애들만 8방으로 번식
				{
					for (int d = 0; d < 8; d++)
					{
						int x = i + dx[d], y = j + dy[d];
						if (isInside(x, y))
						{
							trees[x][y].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter()
{
	// energy 공급
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] += energy[i][j];
}

int check_trees()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cnt += trees[i][j].size();

	return cnt;
}

int main()
{
	freopen("s_input.txt", "r", stdin);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			arr[i][j] = 5; // 초기에는 양분 5만큼으로 초기화

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> energy[i][j];

	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		// (x, y)에 나이 z인 나무있다.
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}

	int year = 0;
	while (true)
	{
		if (year == k)
			break;

		// 봄
		spring();
		// 여름
		summer();
		// 가을
		autumn();
		// 겨울
		winter();
		year++;
	}

	cout << check_trees() << endl;


	return 0;
}

