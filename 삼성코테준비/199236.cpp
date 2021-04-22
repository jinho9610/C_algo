#include <iostream>
#include <cstring>
#include <vector>

#define endl '\n'

using namespace std;

int n, arr[5][5], tmp[5][5];
pair<pair<int, int>, int> shark;
vector<int> eated;
pair<pair<int, int>, int> fishes[17];
bool noFish = false;
int result = 0;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

bool isInside(int x, int y)
{
    return 1 <= x && x <= 4 && 1 <= y && y <= 4;
}

void print_arr()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
            cout << arr[i][j] << ' ';
        // cout << "       ";
        // for (int j = 1; j <= 4; j++)
        //     cout << fishes[arr[i][j]].second << ' ';
        cout << endl;
    }
    cout << endl;
}

// arr2를 arr1으로 복사
void copy_arr(int arr1[5][5], int arr2[5][5])
{
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            arr1[i][j] = arr2[i][j];
}

vector<pair<int, int>> eatableFishes() // 먹을 수 있는 물고기를 고른다
{
    cout << "before eatableFishes()" << endl;
    vector<pair<int, int>> tmp;
    // 먼저 현재 상어 위치 파악
    int x = shark.first.first, y = shark.first.second;
    cout << "shark pos: " << x << ' ' << y << ' ';
    int dir = shark.second; // 상어의 방향
    cout << "shark dir: " << dir << endl;

    int nx = x + dx[dir], ny = y + dx[dir];

    while (isInside(nx, ny))
    {
        //cout << "shark heading to: " << nx << ' ' << ny << endl;
        if (arr[nx][ny])             // 물고기가 있으면
            tmp.push_back({nx, ny}); // 얘도 먹을 수 있는 후보군
        nx += dx[dir], ny += dy[dir];
    }

    return tmp;
}

void fish_move()
{
    // 번호 작은 물고기부터
    cout << shark.first.first << ' ' << shark.first.second << endl;
    print_arr();
    for (int i = 1; i <= 16; i++)
    {
        int dir = fishes[i].second; // 현재 번호 물고기의 방향
        int fx = fishes[i].first.first, fy = fishes[i].first.second;
        if (!arr[fx][fy]) // 이미 해당 번호 물고기가 잡혀먹은 경우
            continue;

        for (int k = 0; k < 8; k++)
        {
            int nx = fx + dx[dir], ny = fy + dy[dir];

            if (!(nx == shark.first.first && ny == shark.first.second) && isInside(nx, ny) && arr[nx][ny] != 0) // 현재 진행방향에 물고기 존재하면
            {
                // 두 물고기 교체
                int target_num = arr[nx][ny]; // 위치 바꾸려는 물고기 위치
                //cout << i << " will replace my place with: " << target_num << endl;
                int tmp = arr[nx][ny];
                arr[nx][ny] = arr[fx][fy];
                arr[fx][fy] = tmp;

                fishes[i].first.first = nx, fishes[i].first.second = ny;
                fishes[i].second = dir;
                fishes[target_num].first.first = fx, fishes[target_num].first.second = fy;
                break;
            }
            else
                dir = (dir + 1) % 8; // 진행방향 반시계방향 회전
        }                            // 8 방향 전부 탐색해도 뭐 없으면
    }
}

void dfs()
{
    // 물고기 이동한다.
    fish_move();
    print_arr();

    // 먹을 물고기 고른다
    vector<pair<int, int>> fishes = eatableFishes();
    cout << "after eatableFishes()" << endl;

    // 더 이상 먹을 수 있는 물고기가 없다면
    if (fishes.size() == 0)
    {
        cout << "=========ate fishes so far: " << endl;
        for (int elem : eated)
            cout << elem << ' ';

        int tot = 0;
        for (int elem : eated)
            tot += elem;
        cout << "         " << tot << "\n\n";
        result = max(result, tot); // 먹은 물고기 번호의 합 갱신
        return;
    }

    else
    {
        for (auto fish : fishes)
        {
            copy_arr(tmp, arr);
            int fx = fish.first, fy = fish.second; // 먹을 수 있는 물고기 위치
            cout << "I ate: " << arr[fx][fy] << endl;
            // 먹고
            eated.push_back(arr[fx][fy]);

            arr[fx][fy] = 0; // 먹어치우고
            pair<pair<int, int>, int> tmp_shark = shark;
            shark = {{fx, fy}, fishes[arr[fx][fy]].second};
            dfs(); // 다음 단계
            shark = tmp_shark;
            eated.pop_back();
            copy_arr(arr, tmp); // 원상복구
        }
    }
}

int main()
{
    freopen("s_input.txt", "r", stdin);

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            int a, b;
            cin >> a >> b;
            arr[i][j] = a; // 물고기 번호는 arr에 기록
            fishes[a] = {{i, j}, b - 1};
        }
    }

    // 최초 상어는 (1, 1) 물고기 먹고, 그 물고기의 방향으로 초기화됨
    shark = {{1, 1}, fishes[arr[1][1]].second};
    arr[1][1] = 0;

    dfs();

    cout << result << endl;

    return 0;
}