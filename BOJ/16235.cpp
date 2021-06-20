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

void sort_trees() // �� ĭ�� �������� ���� ������������ ����
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sort(trees[i][j].begin(), trees[i][j].end());
}

void print_tree_cnt() // �� ĭ�� �ִ� ������ �� ���
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

// ���̸�ŭ ��� �԰� ���� 1����
void spring()
{
	sort_trees(); // ���� �� ĭ�� �������� ���� ������������ ����
	// ��и��Դ� ������ �� �״´�
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			bool flag = true;
			unsigned int k = 0;
			for (k = 0; k < trees[i][j].size(); k++)
			{
				int age = trees[i][j][k]; // ������ ����
				if (arr[i][j] >= age) // �����ִ� ����� ���̺��� ���ٸ�
				{
					arr[i][j] -= age; // ��� �԰�
					trees[i][j][k]++; // ���� 1 ����
				}
				else // k��° �������� �� �̻� ����� ������� �ʴٸ�
				{ // ����ʹ� ��� ���� ���̴� ���� Ż��
					flag = false;
					break;
				}
			}
			if (flag == false) // ���� ������ ����Ѵ�
			{
				int cur = trees[i][j].size() - 1;
				for (int nk = cur; nk >= k; nk--)
				{
					int age = trees[i][j].back(); // ���� ��� ���� �ľ�
					trees[i][j].pop_back(); // ���� ������ �����ϰ�
					dead_trees[i][j].push_back(age); // ���� ������ ��ܿ� �߰�
				}
			}
		}
	}
}

void summer()
{
	// ���� ������ ����� �ȴ�
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int dead : dead_trees[i][j])
				arr[i][j] += dead / 2;
		}
	}
	// �� ���� �� �� ���� ���� ��� �ʱ�ȭ
	memset(dead_trees, 0x00, sizeof(dead_trees));
}

void autumn()
{
	// ���� ����
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (unsigned int k = 0; k < trees[i][j].size(); k++)
			{
				int age = trees[i][j][k];
				if (age % 5 == 0) // ���� % 5 == 0�� �ֵ鸸 8������ ����
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
	// energy ����
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
			arr[i][j] = 5; // �ʱ⿡�� ��� 5��ŭ���� �ʱ�ȭ

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> energy[i][j];

	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		// (x, y)�� ���� z�� �����ִ�.
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}

	int year = 0;
	while (true)
	{
		if (year == k)
			break;

		// ��
		spring();
		// ����
		summer();
		// ����
		autumn();
		// �ܿ�
		winter();
		year++;
	}

	cout << check_trees() << endl;


	return 0;
}

