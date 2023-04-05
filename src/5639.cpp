// BOJ 5639 이진 검색 트리

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

void post_order(Node *root)
{
    if (root == NULL) return;
    post_order(root->left);
    post_order(root->right);
    cout << root->data << '\n';
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int data;
    Node *root = NULL;
    
    while (cin >> data) root = insert(root, data);
    post_order(root);

    return 0;
}