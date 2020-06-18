// *
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
    if (x == -1) {
        return NULL;
    }
    node* root = new node(x);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void updateBst(node* root, int& sum)
{
    if (root == NULL) {
        return;
    }
    updateBst(root->right, sum);
    sum += root->val;
    root->val = sum;
    updateBst(root->left, sum);
}

void printPre(node* root)
{
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    printPre(root->left);
    printPre(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    node* root = buildTree();
    int sum = 0;
    updateBst(root, sum);
    printPre(root);
    return 0;
}