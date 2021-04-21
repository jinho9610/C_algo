#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define endl '\n'

typedef long long ll;

int n, x, arr[21][21];
bool visited[21][21];
vector<pair<int, char>> h_edges, v_edges;

void h_edge_detector(int x) // 어떤 행에서 detection 수행 후 정보 반환
{
    h_edges.clear();
    for (int i = 1; i < n; i++)
    {
        if (arr[x][i] < arr[x][i + 1])
            h_edges.push_back({i, 'L'}); // 내가 내 오른쪽 놈보다 낮다
        else if (arr[x][i] > arr[x][i + 1])
            h_edges.push_back({i, 'H'}); // 내가 내 오른쪽 놈보다 높다
    }
}

void v_edge_detector(int y) // 어떤 행에서 detection 수행 후 정보 반환
{
    v_edges.clear();
    for (int i = 1; i < n; i++)
    {
        if (arr[i][y] < arr[i + 1][y])
            v_edges.push_back({i, 'L'}); // 내가 내 아랫놈보다 낮다
        else if (arr[i][y] > arr[i + 1][y])
            v_edges.push_back({i, 'H'}); // 내가 내 아랫놈보다 높다
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int t_num;
    cin >> t_num;

    for (int t = 1; t <= t_num; t++)
    {
        memset(arr, 0x00, sizeof(arr));
        h_edges.clear();
        v_edges.clear();

        cin >> n >> x;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> arr[i][j];

        int cnt = 0;

        memset(visited, 0x00, sizeof(visited));
        for (int i = 1; i <= n; i++)
        {
            bool settable = true;
            h_edge_detector(i); // 행에 대해서 디텍션 수행
            for (auto h_edge : h_edges)
            {
                // h_edge.second가 H이라면 오른쪽에 경사로 설치
                if (h_edge.second == 'H')
                {
                    // 경사로 설치를 위해서는 다음 edge까지 거리가 x보다 긴지 확인
                    int cur_height = arr[i][h_edge.first + 1];

                    if (abs(cur_height - arr[i][h_edge.first]) > 1)
                        settable = false;

                    else
                    {
                        for (int j = h_edge.first + 1; j <= h_edge.first + x; j++)
                        {
                            if (j > n || cur_height != arr[i][j] || visited[i][j])
                            {
                                settable = false;
                                break;
                            }
                            visited[i][j] = true;
                        }
                    }
                }
                // h_edge.second가 L이라면  왼쪽에 경사로 설치
                else
                {
                    int cur_height = arr[i][h_edge.first];
                    if (abs(cur_height - arr[i][h_edge.first + 1]) > 1)
                        settable = false;

                    else
                    {
                        for (int j = h_edge.first; j > h_edge.first - x; j--)
                        {
                            if (j < 1 || cur_height != arr[i][j] || visited[i][j])
                            {
                                settable = false;
                                break;
                            }
                            visited[i][j] = true;
                        }
                    }
                }
            }
            if (settable)
                cnt++;
        }

        memset(visited, 0x00, sizeof(visited));
        for (int i = 1; i <= n; i++)
        {
            bool settable = true;
            v_edge_detector(i); // 행에 대해서 디텍션 수행
            for (auto v_edge : v_edges)
            {
                // h_edge.second가 H이라면 오른쪽에 경사로 설치
                if (v_edge.second == 'H')
                {
                    // 경사로 설치를 위해서는 다음 edge까지 거리가 x보다 긴지 확인
                    int cur_height = arr[v_edge.first + 1][i];
                    if (abs(cur_height - arr[v_edge.first][i]) > 1)
                        settable = false;

                    else
                    {
                        for (int j = v_edge.first + 1; j <= v_edge.first + x; j++)
                        {
                            if (j > n || cur_height != arr[j][i] || visited[j][i])
                            {
                                settable = false;
                                break;
                            }

                            visited[j][i] = true;
                        }
                    }
                }
                // h_edge.second가 L이라면  아래쪽에 경사로 설치
                else
                {
                    int cur_height = arr[v_edge.first][i];

                    if (abs(cur_height - arr[v_edge.first + 1][i]) > 1)
                        settable = false;

                    else
                    {
                        for (int j = v_edge.first; j > v_edge.first - x; j--)
                        {
                            if (j < 1 || cur_height != arr[j][i] || visited[j][i])
                            {
                                settable = false;
                                break;
                            }
                            visited[j][i] = true;
                        }
                    }
                }
            }
            if (settable)
                cnt++;
        }

        cout << "#" << t << ' ' << cnt << '\n';
    }
    return 0;
}