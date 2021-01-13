#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

int arr[10001];

Node *insert(Node *node, int data)
{
    if (node == NULL)
    {
        node = new Node();
        node->data = data;
        node->left = node->right = NULL;
    }
    else if (data <= node->data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }
    return node;
}

void postorder(Node *node)
{
    if (node->left != NULL)
        postorder(node->left);
    if (node->right != NULL)
        postorder(node->right);
    cout << node->data << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Node *root = NULL;
    int val;           // 전위순회로 읽어온 데이터 하나씩 입력 받기
    while (cin >> val) // eof 전까지 읽는다
    {
        root = insert(root, val); // 입력된 데이터로 이진트리 생성하면서 root 계속 갱신
    }

    postorder(root); // 최종적으로 결정된 루트를 가지고 후위 순회

    return 0;
}