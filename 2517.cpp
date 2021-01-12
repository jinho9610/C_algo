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

void merge(int s, int m, int e)
{
    int p1 = s, p2 = m + 1, k = s;

    while (p1 <= m && p2 <= e)
    {
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
    cin >> n;
    int abil;
    for (int i = 0; i < n; i++)
    {
        cin >> abil;
        runners.push_back(runner(abil, i));
    }
}