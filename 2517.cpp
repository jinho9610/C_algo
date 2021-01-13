//너무 어려움. 나중에 다시 할 것

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;

class runner
{
public:
    ll ability;
    int position;
    runner()
    {
        this->ability = 0;
        this->position = 0;
    }
    runner(ll l, int p)
    {
        this->ability = l;
        this->position = p;
    }
};

int n;
vector<runner> runners;
vector<runner> temp;
vector<int> ranks;

void merge(int s, int m, int e)
{
    int p1 = s, p2 = m + 1, k = s;

    while (p1 <= m && p2 <= e)
    {
        if (runners[p1].ability >= runners[p2].ability)
        {
            temp[k++] = runners[p1++];
        }
        else
        {
            int cnt = m - p1 + 1;               // 현재 몇개가 남아있는지
            ranks[runners[p2].position] -= cnt; // 등수 갱신
            temp[k++] = runners[p2++];
        }
    }
    while (p1 <= m)
    {
        temp[k++] = runners[p1++];
    }
    while (p2 <= e)
    {
        temp[k++] = runners[p2++];
    }
    for (int i = s; i <= e; i++)
    {
        runners[i] = temp[i];
    }
}

void mergeSort(int s, int e)
{
    if (s < e)
    {
        int mid = (s + e) / 2;
        mergeSort(s, mid);
        mergeSort(mid + 1, e);
        merge(s, mid, e);
    }
}

int main()
{
    //inverstion count, merge sort와 연관있음

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int abil;
    for (int i = 0; i < n; i++)
    {
        cin >> abil;
        runners.push_back(runner(abil, i));
        temp.push_back(runner(abil, i));
        ranks.push_back(i + 1); // 각 선수별 등수 현황
    }

    mergeSort(0, n-1);

    for (int i = 0; i < ranks.size(); i++)
        cout << ranks[i] << endl;
}