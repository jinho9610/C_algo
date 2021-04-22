#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

#define endl '\n'

using namespace std;

typedef long long ll;

int n, m, fuel, arr[21][21];
int tx, ty; // taxi x, taxi y
int visited[21][21];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool cantmove = false;

pair<int, int> rider[21][21];
bool isRider[21][21];

bool isInside(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first < p2.first)
        return true;

    else if (p1.first == p2.first)
    {
        if (p1.second < p2.second)
            return true;
        else
            return false;
    }
    else
        return false;
}

pair<int, int> pick_rider()
{
    int min_val = -1;
    memset(visited, 0xff, sizeof(visited)); // -1�� �ʱ�ȭ
    visited[tx][ty] = 0;
    queue<pair<int, int>> q;
    vector<pair<int, int>> tmp;
    q.push({ tx, ty });

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;

        if (min_val == -1)
        {
            if (isRider[x][y]) // �°��߰��ϸ�
            {
                min_val = visited[x][y];
                tmp.push_back({ x, y });
            }
        }
        else
        {
            if (visited[x][y] > min_val)
                break;
            if (isRider[x][y] && min_val == visited[x][y])
                tmp.push_back({ x, y });
        }

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            // ���� ���̰�, �湮������ ���ٸ�
            if (isInside(nx, ny) && arr[nx][ny] != 1 && visited[nx][ny] == -1)
            {
                q.push({ nx, ny });
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
    }

    if (tmp.size() == 0)
        return { 1e9, 1e9 };

    else
    {// tmp���� ���ǿ� �����ϴ� ���� ã�ƾ���
        sort(tmp.begin(), tmp.end(), cmp);
        return tmp[0];
    }
}

void ride(int rx, int ry)
{
    // (rx, ry)�� ���� �¿���� �°��� ��ġ
    //cout << "rxry: " << rx << " " << ry << endl;
    int dest_x = rider[rx][ry].first, dest_y = rider[rx][ry].second;
    //cout << "dest" << dest_x << dest_y << endl;

    memset(visited, 0xff, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({ tx, ty });
    visited[rx][ry] = 0;
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (x == dest_x && y == dest_y)
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (isInside(nx, ny) && visited[nx][ny] == -1 && arr[nx][ny] == 0)
            {
                q.push({ nx, ny });
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
    }
    int len = visited[dest_x][dest_y]; // �̵��ؾ��ϴ� �Ÿ�
    if (len == -1)                     // �°��¿��µ� �������� ���� �Ұ��� ���
    {
        cantmove = true;
        return;
    }
    //cout << "dddd" << len << endl;
    if (len > fuel) // ��������ؼ� �̵����ϴ°��
    {
        cantmove = true;
        return;
    }
    else
    {
        fuel = fuel - len + len * 2;
        isRider[rx][ry] = false;  // ��������� �°�����
        tx = dest_x, ty = dest_y; // �������� �ý���ǥ ����
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("s_input.txt", "r", stdin);

    cin >> n >> m >> fuel;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    cin >> tx >> ty; // �ʱ� �ý� ��ġ

    for (int i = 0; i < m; i++)
    {
        int sx, sy, dx, dy; // (sx, sy) -> (dx, dy)
        cin >> sx >> sy >> dx >> dy;
        rider[sx][sy] = { dx, dy };
        isRider[sx][sy] = true;
    }

    for (int i = 0; i < m; i++)
    {
        pair<int, int> r = pick_rider(); // �°�����
        int rx = r.first, ry = r.second;

        if (rx == 1e9 && ry == 1e9)
        {
            cout << -1 << endl;
            return 0;
        }

        int len = visited[rx][ry]; // �̵��ؾ��ϴ� �Ÿ�
        //cout << len << endl;
        if (len >= fuel) // ���� �����ؼ� �̵����ϴ� ���
        {
            // �°��¿췯 �̵��ϰ� ���� 0�Ǵ� ��쵵 ����� ��� �Ұ�
            cout << -1 << endl;
            return 0;
        }
        else
        {
            fuel -= len; // ���� �Ҹ�
            tx = rx, ty = ry;

            ride(rx, ry);
        }
        //cout << i + 1 << " " << fuel << endl;
        if (cantmove)
        {
            cout << -1 << endl;
            return 0;
        }
        else
            continue;
    }

    cout << fuel << endl;

    return 0;
}
