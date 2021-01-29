#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> food_times, long long k)
{
    int cnt = food_times.size(); // 음식 개수
    int completed = 0;

    int idx = -1;
    while (k--)
    {
        idx++;
        if (idx == cnt)
            idx = 0;

        while (food_times[idx] == 0) // 현재 먹어야할 번호의 음식이 남아있지 않은 경우
        {
            completed++;          // 다먹은 음식 개수 하나 증가
            if (completed == cnt) // 모든 음식을 다 먹은 경우
                return -1;

            idx++;
            if (idx == cnt)
                idx = 0;
        }

        food_times[idx]--; // 음식 먹고
    }

    idx++;
    if (idx == cnt)
        idx = 0;

    return idx + 1;
}

int a()
{
    static int x = 5;
    return x++;
}

int b()
{
    return x;
}

int main()
{
    cout << a() << endl;
    cout << a() << endl;
    cout << a() << endl;

    return 0;
}