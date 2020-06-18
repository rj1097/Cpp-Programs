#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int val;
    node *left, *right;

    node()
    {
        left = right = nullptr;
    }

    node(int d)
        : val(d)
    {
        left = right = nullptr;
    }
};

node* buildTree()
{
    int x;
    cin >> x;
    node* root = new node(x);
    string child;
    cin >> child;
    if (child == "true") {
        root->left = buildTree();
    }
    cin >> child;
    if (child == "true") {
        root->right = buildTree();
    }
    return root;
}

bool searchNode(node* root, int x)
{
    if (root == NULL) {
        return false;
    }
    return (root->val == x) || (searchNode(root->left, x)) || searchNode(root->right, x);
}

node* findLCA(node* root, int x, int y)
{
    if (root->val == x || root->val == y) {
        return root;
    }

    if (searchNode(root->left, x)) {
        if (searchNode(root->left, y)) {
            return findLCA(root->left, x, y);
        } else {
            return root;
        }
    } else {
        if (searchNode(root->right, y)) {
            return findLCA(root->right, x, y);
        } else {
            return root;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    node* root = buildTree();
    int x, y;
    cin >> x >> y;
    node* lca = findLCA(root, x, y);
    cout << lca->val;
    return 0;
}