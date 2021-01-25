#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>

using namespace std;

#define MAX 101

int n, m;
int recommend[MAX];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // n: 사진틀의 개수 m: 추천 횟수
    cin >> n >> m;

    vector<pair<int, int>> pictures(n, make_pair(0, 0)); // (시간, 학생 번호)

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        recommend[num]++; // 추천 받은 횟수 갱신

        bool replace = true;
        for (int j = 0; j < pictures.size(); j++) // 학생들 순차탐색
        {
            if (pictures[j].second == 0) // 비어있는 액자발견하면
            {
                pictures[j].second = num; // 학생번호
                pictures[j].first = i;    // 타임스탬프
                replace = false;          // 교체할 필요 없음
                break;
            }
            else if (pictures[j].second == num) // 이미 액자에 있다면 따로 교체 불필요
            {
                replace = false;
                break;
            }
        }

        if (replace)
        {
            int idx = 0; // 교체를 위해서 삭제되어야 할 학생 번호
            for (int j = 1; j < n; j++) // 사진틀에 걸려있는 놈들끼리 비교
            {
                if (recommend[pictures[j].second] == recommend[pictures[idx].second])
                {
                    if (pictures[j].first < pictures[idx].first) // 추천수 제일 낮게 받은 학생 두명일 경우, 타임스탬프 비교
                        idx = j;
                }
                else if (recommend[pictures[j].second] < recommend[pictures[idx].second])
                {
                    idx = j;
                }
            }
            recommend[pictures[idx].second] = 0; // 교체된 학생은 추천횟수 0
            pictures[idx].first = i;             // 교체된 학생의 타임스탬프 교체
            pictures[idx].second = num;
        }
    }
    sort(pictures.begin(), pictures.end(), cmp);
    for (int i = 0; i < pictures.size(); i++)
    {
        cout << pictures[i].second << ' ';
    }
}