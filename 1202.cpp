#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

class jewel
{
public:
    int value;
    int weight;
    jewel(int weight, int value)
    {
        this->value = value;
        this->weight = weight;
    }
};

struct cmp
{
    bool operator()(jewel &j1, jewel &j2)
    {
        return j1.value < j2.value;
    }
};

int n, k;

vector<int> bags;
vector<jewel> jewels;
priority_queue<jewel, vector<jewel>, cmp> pq; // 보석의 가격이 비쌀수록 우선순위 높음

bool jewel_cmp(jewel j1, jewel j2)
{
    return j1.weight < j2.weight;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 1. 남은 가방 중 제일 작은 가방 선택 -> 정렬
    // 2. 선택된 가방에 넣을 수 있는 보석 힙에 넣기
    // 3. 힙에서 가장 비싼 보석 선택 후 제거
    // 4. 다음 가방 선택 후 반복
    cin >> n >> k;
    int m, v, c;
    for (int i = 0; i < n; i++) // 보석의 무게, 가격 입력 받기
    {
        cin >> m >> v;
        jewels.push_back(jewel(m, v));
    }

    for (int i = 0; i < k; i++) // 가방이 수용가능한 무게정보 입력
    {
        cin >> c;
        bags.push_back(c);
    }

    sort(jewels.begin(), jewels.end(), jewel_cmp); // 보석 무게별로 오름차순 정렬
    sort(bags.begin(), bags.end());                // 가방 수용능력 오름차순 정렬

    ll result = 0; // 훔칠 수 있는 보석 가격 총합
    int idx = 0;
    for (int i = 0; i < k; i++)
    {
        int bag_capacity = bags[i]; // 현재 가방에 담을 수 있는 무게
        for (int j = idx; j < n; j++)
        {
            if (jewels[j].weight > bag_capacity) // 수용가능무게 벗어나는 보석발견하면 break
            {
                 // 이미 큐에 넣은 보석들에 대해서 또 탐색할 필요 없으니, 다음번에 탐색을 시작할 지점 인덱스 기록
                break;
            }
            idx++;
            pq.push(jewels[j]); // 가방 수용능력보다 무게가 작은 보석은 pq에 넣음
        }
        //가장 비싼 녀석 꺼내오기
        if (!pq.empty()) // pq가 비어있지 않다면
        {
            result += pq.top().value;
            pq.pop();
        }
    }

    cout << result << "\n";

    return 0;
}