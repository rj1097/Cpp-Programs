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

void addNode(node*& root, int x)
{
    if (root == NULL) {
        root = new node(x);
        return;
    }

    if (x < root->val) {
        addNode(root->left, x);
    } else {
        addNode(root->right, x);
    }
}
node* buildTree()
{

    int n;
    cin >> n;
    node* root = NULL;
    while (n--) {
        int x;
        cin >> x;
        addNode(root, x);
    }
    return root;
}

node* findLCA(node* root, int a, int b)
{
    if (root->val == a || root->val == b) {
        return root;
    }

    if (root->val < a) {
        if (root->val >= b) {
            return root;
        } else {
            return findLCA(root->right, a, b);
        }
    } else {
        if (root->val < b) {
            return root;
        } else {
            return findLCA(root->left, a, b);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    node* root = buildTree();
    // cout << root->val << "--" << root->left->val << "--" << root->right->val;
    int a, b;
    cin >> a >> b;
    node* lca = findLCA(root, a, b);
    cout << lca->val;
    return 0;
}
