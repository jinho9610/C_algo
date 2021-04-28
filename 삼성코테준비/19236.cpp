#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define endl '\n'

typedef pair<int, int> pii;
typedef long long ll;

struct FISH
{
	int x, y, dir;
	bool isAlive;
	
	void print()
	{
		if(isAlive)
			cout << "x: " << this->x << "  y: " << this->y << "  ����: " << dir << "   �������" << endl;
		else
			cout << "x: " << this->x << "  y: " << this->y << "  ����: " << dir << "   �׾���" << endl;
	}
};

struct SHARK
{
	int x, y, dir;
};

FISH fishes[17], tmp_fishes[17];
int arr[4][4], tmp_arr[4][4], result = 0;
SHARK shark;

int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };

bool isInside(int x, int y)
{
	return 0 <= x && x < 4 && 0 <= y && y < 4;
}

void backup(int arr1[][4], FISH arr2[])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			arr1[i][j] = arr[i][j];
	}
	for (int i = 1; i <= 16; i++)
	{
		arr2[i] = fishes[i];
	}
}

void load(int arr1[][4], FISH arr2[])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			arr[i][j] = arr1[i][j];
	}
	for (int i = 1; i <= 16; i++)
	{
		fishes[i] = arr2[i];
	}
}

void status_changer(int sx, int sy, int fx, int fy, int fish_num, bool flag)
{
	//fish_num  - ������ ����Ⱑ �ִ� ��ġ
	// flag�� true�̸� ������ ��Ȳ��
	if (flag)
	{
		arr[sx][sy] = 0;
		arr[fx][fy] = -1;
		fishes[fish_num].isAlive = false;
	}
	else // �Ծ����� ���
	{
		arr[sx][sy] = -1;
		arr[fx][fy] = fish_num;
		fishes[fish_num].isAlive = true;
	}
}

void swap_fish(int fx1, int fy1, int fx2, int fy2)
{
	int f1 = arr[fx1][fy1];
	int f2 = arr[fx2][fy2];

	// �ϴ� arr �迭���� ����� ��ȣ �ٲ��ְ�
	int tmp = arr[fx1][fy1];
	arr[fx1][fy1] = arr[fx2][fy2];
	arr[fx2][fy2] = tmp;

	fishes[f1].x = fx2, fishes[f1].y = fy2;
	fishes[f2].x = fx1, fishes[f2].y = fy1;

}

void fish_move()
{
	for (int i = 1; i <= 16; i++) // 1�� �������� �����δ�
	{
		// �̹� ���� ������� �Ű澲�� x
		if (fishes[i].isAlive == false)
			continue;

		int fx = fishes[i].x, fy = fishes[i].y; // ���� ����� ��ġ

		for (int k = 0; k < 8; k++)
		{
			// ���� ����� ���� ������ fishes[i].dir
			// ����Ⱑ ���� ���� ������ �������� �� ĭ ������ ����� ��ǥ
			int nfx = fx + dx[fishes[i].dir], nfy = fy + dy[fishes[i].dir]; 

			if (isInside(nfx, nfy) && arr[nfx][nfy] != -1)
			{
				// ��ĭ�� ���
				if (arr[nfx][nfy] == 0)
				{
					fishes[i].x = nfx, fishes[i].y = nfy; // ����� ��ġ �ܼ� ����
					arr[nfx][nfy] = i;
					arr[fx][fy] = 0;
				}
				// ����ִ� ����� �����ϴ� ��� exchange
				else if (arr[nfx][nfy] > 0 && fishes[arr[nfx][nfy]].isAlive)
				{
					swap_fish(fx, fy, nfx, nfy);
				}
				break;
			}
			else
				fishes[i].dir = (fishes[i].dir + 1) % 8; // 45�� �ݽð� ���� ȸ��
		}
	}
}

void print_arr()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << arr[i][j] << ' ';

		cout << "\t\t";
		for (int j = 0; j < 4; j++)
			cout << fishes[arr[i][j]].dir << ' ';

		cout << endl;
	}
}

void dfs(int sx, int sy, int s_dir, int sum)
{
	int tmp[4][4];
	FISH tmp_fishes[17];
	//cout << sx << ' ' << sy << endl;
	backup(tmp, tmp_fishes);

	// sum�� ���ݱ��� ���� ����� ��ȣ�� ��
	result = max(result, sum);
	

	// ����� �����δ�
	fish_move();
	//print_arr();

	for (int i = 1; i <= 3; i++)
	{
		//cout << s_dir << endl;
		int fx = sx + i * dx[s_dir], fy = sy + i * dy[s_dir]; // ���� �ٶ󺸴� ���⿡�� ���� �� �ִ� ������� ��ġ
		int fish_num = arr[fx][fy];
		
		int fish_dir = fishes[fish_num].dir;

		if (fish_num == 0)
			continue;

		if (!isInside(fx, fy)) // ���� ���� �����̰ų� �̶�� ���� �� ����.
			continue;
		
		if (fishes[fish_num].isAlive == false) // ���� ������� ���� �� ����
			continue;

		status_changer(sx, sy, fx, fy, fish_num, true); // �Դ´�
		//cout << i << "��° for���̰� " << fx << ", " << fy << " �� �ִ� " << fish_num << " �Ծ���." << endl;
		dfs(fx, fy, fish_dir, sum + fish_num); // ���� ����� �Դ´�
		status_changer(sx, sy, fx, fy, fish_num, false); // ��´�
		//cout << i << "��° for���̰� " << fx << ", " << fy << " �� �ִ� " << fish_num << " �����." << endl;

		//cout << endl;
	}

	load(tmp, tmp_fishes);
	//cout << "=================================" << endl;
}

int main()
{
	freopen("s_input.txt", "r", stdin);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int fish_num, dir;
			cin >> fish_num >> dir;
			arr[i][j] = fish_num;
			fishes[fish_num] = { i,j, dir - 1, true };
		}
	}

	int start_num = arr[0][0];
	int shark_dir = fishes[start_num].dir;
	
	fishes[start_num].isAlive = false; // (0, 0)�� �ִ� ����� ����
	arr[0][0] = -1; // (0, 0)�� ��� ��ġ��

	dfs(0, 0, shark_dir, start_num);

	cout << result << endl;

	return 0;
}