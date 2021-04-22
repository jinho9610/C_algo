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
int prior[401][5][4]; // ��� ��ȣ, ���� �ٶ󺸴� ����
pii scents[21][21]; // ���� �ʿ� �������ִ� ���� ����
SHARK shark[401];

int dx[] = { 0, -1, 1, 0, 0 }; // �����¿�
int dy[] = { 0, 0, 0, -1, 1 };

bool isInside(int x, int y)
{
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

// ���� ���� �Լ�
void decrease_scents()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (scents[i][j].second > 0)
			{
				scents[i][j].second--;
				if (scents[i][j].second == 0) // ������ �ϳ��� �ȳ���������
					scents[i][j].first = 0; // ������ ���� ��� ��ȣ�� ���ֹ���(0���� ����) (��ȿ�� ��� ��ȣ�� 1�̻��̴ϱ�)
			}
		}
	}
}

// �� �ȿ� �����ִ� ��� �� üũ�ϴ� �Լ�
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

	for (int i = 1; i <= m; i++) // m������ �� ���ؼ�
	{
		if (shark[i].isInmap == false) // �� �ȿ� ���� ���� �� ���ؼ��� ��� x
			continue;

		int x = shark[i].x, y = shark[i].y; // ��� ��ġ
		int staring_dir = shark[i].dir; // ���� �ٶ󺸴� ����
		
		bool flag1 = false;

		// 1. ���� �� ���� �ľ�
		for (int heading : prior[i][staring_dir]) // Ž�� ����
		{
			int nx = x + dx[heading], ny = y + dy[heading];

			if (isInside(nx, ny) && scents[nx][ny].second == 0) // ������ ���� �����̶��
			{
				// ����̵� �ϰ� ������ (k + 1)��ŭ �����
				// ��� ��� �̵� �� 1�� ���ҽ�ų ���̴ϱ�
				tmp[nx][ny].push_back(i);
				shark[i].x = nx, shark[i].y = ny, shark[i].dir = heading;
				flag1 = true; // ù��° �켱���� ������ ��
				break;
			}
		}

		if (flag1 == false) // ù �켱 ����(���� ���� �� ������ ���� ������ ����)�� �������� ���� ���
		{
			for (int heading : prior[i][staring_dir])
			{
				int nx = x + dx[heading], ny = y + dy[heading];
				if (isInside(nx, ny) && scents[nx][ny].first == i) // ���� ������ ���� ���� ���δٸ�
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
			
			sort(tmp[i][j].begin(), tmp[i][j].end()); // �������� ����
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
			if (a != 0) // a�� ����� ��ġ
			{
				shark[a] = { i, j, 0, true }; // ������ 1~4�� ���Ŀ� �ʱ�ȭ���ٰ�
				scents[i][j] = { a, k }; // �ʱ���¿� a �� (i, j)�� �����ϰ� �� �ڸ��� k��ŭ ����
			}
		}
	}
	for (int i = 1; i <= m; i++) // m���� ���
	{
		int d;
		cin >> d;
		shark[i].dir = d; // ����� �ʱ� ���� �ʱ�ȭ
	}

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= 4; j++)
			for (int k = 0; k < 4; k++)
				cin >> prior[i][j][k];

	int sec = 0;
	while (true)
	{
		if (left_sharks() == 1 && shark[1].isInmap) // ��� �ϳ��� ���� ���
			break; // ����

		if (sec >= 1000 && left_sharks() != 1)
		{
			cout << -1 << endl;
			return 0;
		}
		// ��� �̵�
		move_sharks();
		// ���� ����
		decrease_scents();

		sec++;
	}

	cout << sec << endl;
	return 0;
}