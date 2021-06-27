/* BOJ 11728 배열 합치기 */
/* 투포인터 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>

#define endl '\n'

using namespace std;

typedef long long ll;

//int n, m, arr[2000002]; // sort를 이용한 풀이에 사용되는 변수
int n, m, arr1[1000001], arr2[1000001], arr[1000001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;

	/* sort 함수를 이용한 정렬 풀이 */
	/*for (int i = 1; i <= n + m; i++)
		cin >> arr[i];
	
	sort(arr + 1, arr + 1 + n + m);

	for (int i = 1; i <= n + m; i++)
		cout << arr[i] << ' ';

	cout << endl;*/

	/* 투 포인터를 이용한 풀이 */
	for (int i = 1; i <= n; i++)
		cin >> arr1[i];
	for (int i = 1; i <= m; i++)
		cin >> arr2[i];
	
	// arr1과 arr2의 오름차순 사전 정렬
	sort(arr1 + 1, arr1 + 1 + n);
	sort(arr2 + 1, arr2 + 1 + m);

	int arr1_idx = 1, arr2_idx = 1;
	for (int i = 1; i <= n + m; i++)
	{
		if (arr1_idx > n) // 이미 arr1 배열의 모든 원소를 arr로 옮긴 상태면
			arr[i] = arr2[arr2_idx++]; // arr2의 원소를 arr에 옮김
		else if (arr2_idx > m) // 이미 arr2 배열의 모든 원소를 arr로 옮긴 상태면
			arr[i] = arr1[arr1_idx++]; // arr1의 원소를 arr로 옮김
		// arr1과 arr2 중 더 작은 값을 갖는 원소를 arr로 옮기고 포인터 증가
		else if (arr1[arr1_idx] < arr2[arr2_idx])
			arr[i] = arr1[arr1_idx++];
		else if (arr1[arr1_idx] >= arr2[arr2_idx])
			arr[i] = arr2[arr2_idx++];
	}

	for (int i = 1; i <= n + m; i++)
		cout << arr[i] << ' ';

	cout << endl;

	return 0;
}
