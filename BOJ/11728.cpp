/* BOJ 11728 �迭 ��ġ�� */
/* �������� */
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

//int n, m, arr[2000002]; // sort�� �̿��� Ǯ�̿� ���Ǵ� ����
int n, m, arr1[1000001], arr2[1000001], arr[1000001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;

	/* sort �Լ��� �̿��� ���� Ǯ�� */
	/*for (int i = 1; i <= n + m; i++)
		cin >> arr[i];
	
	sort(arr + 1, arr + 1 + n + m);

	for (int i = 1; i <= n + m; i++)
		cout << arr[i] << ' ';

	cout << endl;*/

	/* �� �����͸� �̿��� Ǯ�� */
	for (int i = 1; i <= n; i++)
		cin >> arr1[i];
	for (int i = 1; i <= m; i++)
		cin >> arr2[i];
	
	// arr1�� arr2�� �������� ���� ����
	sort(arr1 + 1, arr1 + 1 + n);
	sort(arr2 + 1, arr2 + 1 + m);

	int arr1_idx = 1, arr2_idx = 1;
	for (int i = 1; i <= n + m; i++)
	{
		if (arr1_idx > n) // �̹� arr1 �迭�� ��� ���Ҹ� arr�� �ű� ���¸�
			arr[i] = arr2[arr2_idx++]; // arr2�� ���Ҹ� arr�� �ű�
		else if (arr2_idx > m) // �̹� arr2 �迭�� ��� ���Ҹ� arr�� �ű� ���¸�
			arr[i] = arr1[arr1_idx++]; // arr1�� ���Ҹ� arr�� �ű�
		// arr1�� arr2 �� �� ���� ���� ���� ���Ҹ� arr�� �ű�� ������ ����
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
