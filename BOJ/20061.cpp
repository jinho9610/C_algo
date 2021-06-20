#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

typedef pair<int, int> pii;

int n, score;
bool R[4][4], G[6][4], B[4][6];

int one_block_sliding(int x, int y, int board_type)
{
	if (board_type == 0) // G ����
	{
		// y�� �ǹ��ִ� ������
		int i = 0;
		for (i = 0; i < 6; i++)
		{
			if (G[i][y] == false) // ����� ������
				continue; // i������ �� �� ������ �ǹ��Ѵ�.
			else
			{ // i-1������ �����̵� �������� �ǹ�
				break;
			}
		}
		return i - 1;
	}
	else
	{
		// x�� �ǹ��ִ� ������
		int i = 0;
		for (i = 0; i < 6; i++)
		{
			if (B[x][i] == false)
				continue;
			else
				break;
		}
		return i - 1;
	}
}

void green_trans(int x, int y, int type)
{
	if (type == 1) // 1x1 ���
	{
		// �ܼ��� �Ʒ��� �����̵�
		// dest������ �����̵� �������� �ǹ�
		int dest = one_block_sliding(x, y, 0);

		G[dest][y] = true;
	}
	else if (type == 2) // ���� ����
	{
		int dest_l = one_block_sliding(x, y, 0);
		int dest_r = one_block_sliding(x, y + 1, 0);

		int dest = min(dest_l, dest_r);

		G[dest][y] = true, G[dest][y + 1] = true;
	}
	else if (type == 3) // ���� ����
	{
		int dest = one_block_sliding(x + 1, y, 0);

		G[dest - 1][y] = true, G[dest][y] = true;
	}
}

void blue_trans(int x, int y, int type)
{
	if (type == 1) // 1x1 ���
	{
		// �ܼ��� ���������� �����̵�
		// dest������ �����̵� �������� �ǹ�
		int dest = one_block_sliding(x, y, 1);
		B[x][dest] = true;
	}
	else if (type == 2) // ���� ����
	{
		int dest = one_block_sliding(x, y + 1, 1);

		B[x][dest - 1] = true, B[x][dest] = true;
	}
	else if (type == 3) // ���� ����
	{
		int dest_u = one_block_sliding(x, y, 1);
		int dest_d = one_block_sliding(x + 1, y, 1);

		int dest = min(dest_u, dest_d);

		B[x][dest] = true, B[x + 1][dest] = true;
	}
}

pii check_g_row_full()
{
	bool first_found = true;
	int thres = 0, cnt = 0;
	for (int i = 0; i < 6; i++)
	{
		bool flag = true;
		for (int j = 0; j < 4; j++)
		{
			if (G[i][j] == false)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cnt++; // ������ ���� ��
			if (first_found)
			{
				thres = i; // ���� ó�� ���� �Ǳ� ������ ����Ʈ
				first_found = false;
			}
			for (int j = 0; j < 4; j++)
				G[i][j] = false;
		}
	}

	score += cnt;

	return { thres, cnt };
}

pii check_b_col_full()
{
	bool first_found = true;
	int thres = 0, cnt = 0;
	for (int j = 0; j < 6; j++)
	{
		bool flag = true;
		for (int i = 0; i < 4; i++)
		{
			if (B[i][j] == false)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cnt++;
			if (first_found)
			{
				thres = j;
				first_found = false;
			}
			for (int i = 0; i < 4; i++)
				B[i][j] = false;
		}
	}
	score += cnt;

	return { thres, cnt };
}

void green_align(int thres, int cnt)
{
	for (int i = thres - 1; i >= 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			G[i + cnt][j] = G[i][j];

			if (i < cnt)
				G[i][j] = false;
		}
	}
}

void blue_align(int thres, int cnt)
{
	for (int j = thres - 1; j >= 0; j--)
	{
		for (int i = 0; i < 4; i++)
		{
			B[i][j + cnt] = B[i][j];

			if (j < cnt)
				B[i][j] = false;
		}
	}
}

void green_remove(int cnt)
{
	// cnt��ŭ �Ʒ��� ����
	for (int i = 6 - cnt; i < 6; i++)
		for (int j = 0; j < 4; j++)
			G[i][j] = false;

	for (int i = 5 - cnt; i >= 0; i--) // ��� ��Ͽ� ���ؼ� 
	{
		for (int j = 0; j < 4; j++)
		{
			G[i + cnt][j] = G[i][j];
			if (i < cnt)
				G[i][j] = false;
		}
	}
}

void blue_remove(int cnt)
{
	// cnt��ŭ �Ʒ��� ����
	for (int j = 6 - cnt; j < 6; j++)
		for (int i = 0; i < 4; i++)
			B[i][j] = false;

	for (int j = 5 - cnt; j >= 0; j--) // ��� ��Ͽ� ���ؼ� 
	{
		for (int i = 0; i < 4; i++)
		{
			B[i][j + cnt] = B[i][j];

			if (j < cnt)
				B[i][j] = false;
		}
	}
}

void check_g_special()
{
	int cnt = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (G[i][j] == true)
			{
				cnt++;
				break;
			}
		}
	}

	green_remove(cnt);
}

void check_b_special()
{
	int cnt = 0;
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (B[i][j] == true)
			{
				cnt++;
				break;
			}
		}
	}

	blue_remove(cnt);
}

void print_G()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (G[i][j])
				cout << 'O' << ' ';
			else
				cout << 'X' << ' ';
		}
		cout << '\n';
	}
}

void print_B()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (B[i][j])
				cout << 'O' << ' ';
			else
				cout << 'X' << ' ';
		}
		cout << '\n';
	}
}

int check_remains()
{
	int cnt = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (G[i][j] == true)
				cnt++;
			if (B[j][i] == true)
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("s_input.txt", "r", stdin);

	cin >> n;

	while (n--)
	{
		pii tmp;
		int x, y, t;
		cin >> t >> x >> y;
		// t: 1-(x, y)   2-(x,y) (x, y+1) ����    3-(x,y) (x+1, y) tpfh

		// �ϴ� �����  G�� B�� �ű� �� �־����
		green_trans(x, y, t);
		blue_trans(x, y, t);

		tmp = check_g_row_full();
		green_align(tmp.first, tmp.second);
		tmp = check_b_col_full();
		blue_align(tmp.first, tmp.second);

		check_g_special();
		check_b_special();
	}

	cout << score << endl;
	cout << check_remains() << endl;

	return 0;
}