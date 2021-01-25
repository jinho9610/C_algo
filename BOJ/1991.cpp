#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Node
{
public:
    char value;
    Node *left;
    Node *right;
    Node()
    {
        this->value = 0;
        this->left = NULL;
        this->right = NULL;
    }
};

typedef long long ll;

int n;
Node tree[27];

void preOrder(Node node)
{
    cout << node.value;

    if (node.left != NULL)
        preOrder(*node.left);
    if (node.right != NULL)
        preOrder(*node.right);
}

void inOrder(Node node)
{
    if (node.left != NULL)
        inOrder(*node.left);

    cout << node.value;

    if (node.right != NULL)
        inOrder(*node.right);
}

void postOrder(Node node)
{
    if (node.left != NULL)
        postOrder(*node.left);
    if (node.right != NULL)
        postOrder(*node.right);

    cout << node.value;
}

int main()
{

    cin >> n;
    char v, l, r;
    for (int i = 0; i < n; i++)
    {
        cin >> v >> l >> r;
        tree[v - 'A'].value = v;
        if (l != '.')
            tree[v - 'A'].left = &tree[l - 'A'];
        if (r != '.')
            tree[v - 'A'].right = &tree[r - 'A'];
    }

    preOrder(tree[0]);
    cout<<'\n';
    inOrder(tree[0]);
    cout<<'\n';
    postOrder(tree[0]);
    cout<<'\n';

    return 0;
}