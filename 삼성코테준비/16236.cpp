#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define endl '\n'

using namespace std;

int n, arr[21][21], visited[21][21], sec;
int fish_cnt;
int shark_size = 2, eaten_fish, shark_x, shark_y;
bool cantEat = false;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// 비교 함수
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

bool isInside(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

// 크기 증가
void grow()
{
    if (shark_size == eaten_fish)
    {
        shark_size++;
        eaten_fish = 0;
    }
}

// 먹으려는 물고기 결정하는 함수
void bfs()
{
    memset(visited, 0xff, sizeof(visited));
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;

    visited[shark_x][shark_y] = 0;
    q.push({shark_x, shark_y});

    bool found = false;
    int found_val = 0;
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;

        if (found && visited[x][y] > found_val)
            break;

        if (!found && (1 <= arr[x][y] && arr[x][y] <= 6) && shark_size > arr[x][y])
        {
            found = true;
            found_val = visited[x][y];
        }
        if (found && (1 <= arr[x][y] && arr[x][y] <= 6) && shark_size > arr[x][y] && visited[x][y] == found_val)
            v.push_back({x, y});
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (isInside(nx, ny) && visited[nx][ny] == -1 && shark_size >= arr[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
    }

    if (v.size() == 0) // 집이먹을 수 있는 물고기가 없는 경우
        cantEat = true;
    else
    {
        //cout << v.size() << endl;
        sort(v.begin(), v.end(), cmp);
        //cout << "eating " << v[0].first << ' ' << v[0].second << endl;
        arr[v[0].first][v[0].second] = 0; // 먹힌 물고기 자리는 0
        shark_x = v[0].first, shark_y = v[0].second;
        eaten_fish++; //먹은 물고기 수 count();
        sec += found_val;
        grow(); // 크기 증가 필요하면 한다
    }
}

int main()
{
    freopen("s_input.txt", "r", stdin);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            if (1 <= arr[i][j] && arr[i][j] <= 6)
                fish_cnt++;
            if (arr[i][j] == 9) // 아기 상어 위치
            {
                shark_x = i, shark_y = j;
                arr[i][j] = 0; // 굳이 상어의 위치 기록할 필요 없다
            }
        }
    }

    while (true)
    {
        if (fish_cnt == 0) // 물고기 다 먹었으면 엄마 상어 부르고
        {
            cout << sec << '\n';
            return 0;
        }

        // 먹을 수 있는 것 찾고 먹는다
        bfs();

        if (cantEat)
        {
            cout << sec << '\n';
            return 0;
        }
        // 크기 업데이트
    }

    return 0;
}