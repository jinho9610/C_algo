#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define endl '\n'

struct BLOCK
{
	int type;
	int pos;
};

int n, prior[9][8];
int real_arr[201][5], arr[201][5];
vector<BLOCK> opers;
vector<int> events;
int cur_height[5];
int max_height;
int score, result;

int dx[] = { 0, 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 0,-1, -1, -1, 0, 1, 1, 1 };

void copy_arr()
{
	for (int i = 1; i <= max_height + 5; i++)
		for (int j = 1; j <= 4; j++)
			arr[i][j] = real_arr[i][j];
}

void print_arr(int mh)
{
	for (int i = mh; i >= 1; i--)
	{
		for (int j = 1; j <= 4; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

void calc_max_height()
{
	for (int i = 1; i <= 4; i++)
		max_height = max(max_height, cur_height[i]);
}

void gravity(int type, int pos)
{
	// pos�� ����߸� ��
	arr[cur_height[pos] + 1][pos] = type;
	cur_height[pos]++;
}

void align_arr()
{
	calc_max_height();

	int tmp[201][5];

	for (int j = 1; j <= 4; j++)
	{
		int cnt = 0;
		for (int i = 1; i <= 199; i++)
		{
			arr[i - cnt][j] = arr[i][j];
			if (arr[i][j] == 0)
				cnt++;
		}
	}
}

bool isInside(int x, int y)
{
	return 1 <= x && 1 <= y && y <= 4;
}

bool bottom_clean() // �긦 ȣ���ؼ� false ��ȯ�Ǹ� �Ʒ��� ���� ���ϴ� ��
{
	bool flag = true;
	for (int j = 1; j <= 4; j++)
	{
		if (arr[1][j] == 0)
		{
			flag = false;
			break;
		}
	}
	if (!flag)
	{
		return flag;
	}

	else if (flag)
	{
		for (int j = 1; j <= 4; j++)
			arr[1][j] = 0; // ���� �Ʒ� �� ����� ���������� ����
	}

	for (int i = 1; i <= 4; i++)
		max_height = max(max_height, cur_height[i]);

	for (int i = 1; i <= max_height + 1; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			arr[i][j] = arr[i + 1][j];
		}
	}

	for (int i = 1; i <= 4; i++)
		cur_height[i]--;

	score++;
	//cout << 1231231 << endl;

	calc_max_height(); // ���߿� ������ �ɵ�
}

void move_blocks()
{
	calc_max_height();
	vector<int> tmp[201][5];
	for (int i = 1; i <= max_height; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			int block_type = arr[i][j];
	
			if (arr[i][j] == 0)
				continue;

			for (int k = 0; k < 8; k++)
			{
				int dir = prior[block_type][k];
				//cout << "��� ��ȣ�� "<<block_type << "��� �� ��: " << dir << endl;
				// ����� �Űܰ� �ڸ�
				int nx = i + dx[dir], ny = j + dy[dir];

				
				if (!isInside(nx, ny)) // �̵����ϸ� �׳� for�� ����ħ
					continue;

				//cout << i << ", " << j << "�� �ִ� " << arr[i][j] << "�� ������ ������ " << dir << "�̴�" << endl;
				arr[i][j] = 0; // ���� ���� �ִ� ���� ����
				tmp[nx][ny].push_back(block_type);
				break;
			}
		}
	}

	for (int i = 1; i <= 4; i++)
		cur_height[i] = 0;

	for (int i = 1; i <= max_height + 1; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (tmp[i][j].size() == 0)
			{
				if (arr[i][j] > 0)
					cur_height[j]++;
				continue;
			}
			sort(tmp[i][j].begin(), tmp[i][j].end());
			arr[i][j] = tmp[i][j][0];
			if (arr[i][j] > 0)
				cur_height[j]++;
		}
	}

	calc_max_height(); // ���߿� ������ �ɵ�?
}

void dfs(int cnt, int amb_cnt)
{
	if (cnt == amb_cnt)
	{
		copy_arr(); // arr�ʱ�ȭ
		for (int i = 1; i <= 4; i++)
			cur_height[i] = 1;
		score = 0;
		int tt = 0;
		for (int i = 0; i < opers.size(); i++)
		{
			int block_type = opers[i].type;
			int block_pos = opers[i].pos;

			if (block_pos == 0)
				block_pos = events[tt++];

			gravity(block_type, block_pos); // ����߸���
			
			//cout << block_pos << "���� " << block_type << "�� ��� ����߸� ����" << endl;
			//print_arr(6);
			//cout << endl;
			bool isFull = true;
			isFull = bottom_clean(); // �ִ��� �� �����
			while (isFull)
				isFull = bottom_clean();
			/*cout << block_pos << "���� " << block_type << "�� ��� ����߸��� ������������ϸ� ����" << endl;
			print_arr(6);
			cout << endl;*/
			move_blocks();
			//cout << block_pos << "���� " << block_type << "�� ��� ����߸��� ��� ������" << endl;
			//print_arr(6);
			//cout << endl;
			align_arr();
			//cout << block_pos << "���� " << block_type << "�� ��� ������ �Ʒ��� ����" << endl;
			//print_arr(6);
			//cout << endl;

			isFull = true;
			isFull = bottom_clean(); // �ִ��� �� �����
			while (isFull)
				isFull = bottom_clean();

			//cout << block_pos << "���� " << block_type << "�� ��� ����߸� �� ���" << endl;
			//print_arr(6);
			//cout << "���� ���� ����(�ְ���̴� " << max_height << ") �̴�.\n";
			//for (int i = 1; i <= 4; i++)
			//	cout << cur_height[i] << ' ';
			//cout << "\n\n";
		}
		result = max(result, score);
		return;
	}

	for (int i = 1; i <= 4; i++)
	{
		events.push_back(i);
		dfs(cnt + 1, amb_cnt);
		events.pop_back();
	}
}

int main()
{
	freopen("s_input.txt", "r", stdin);

	cin >> n;

	for (int i = 1; i <= 8; i++) // ��Ϻ� �켱���� �ݿ�
	{
		for (int j = 0; j < 8; j++)
		{
			int a;
			cin >> a;
			prior[i][j] = a;
		}
	}

	int amb_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int k, c;
		cin >> k >> c;
		opers.push_back({ k, c });
		if (c == 0) amb_cnt++;
	}

	//print_arr(10);
	//gravity(3, 1);
	//gravity(7, 2);
	//gravity(4, 1);
	//gravity(3, 3);
	//gravity(6, 4);
	//cout << endl;
	//
	//print_arr(10);
	//cout << endl;
	////bottom_clean();
	////cout << endl;
	//print_arr(10);
	//cout << endl;
	//move_blocks();
	//cout << endl;
	//print_arr(10);
	//cout << endl;
	//align_arr();
	//cout << endl;
	//print_arr(10);

	//cout << endl;
	//for (int i = 1; i <= 4; i++)
	//	cout << cur_height[i] << ' ';
	//cout << endl;
	//cout << amb_cnt << endl;
	dfs(0, amb_cnt);
	cout << result << endl;

	return 0;
}