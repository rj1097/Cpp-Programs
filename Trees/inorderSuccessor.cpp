// BST

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
    if (x <= root->val) {
        addNode(root->left, x);
    } else {
        addNode(root->right, x);
    }
}
node* buildBst()
{
    int n;
    cin >> n;
    int x;
    node* root = NULL;
    while (n--) {
        cin >> x;
        addNode(root, x);
    }
    return root;
}

bool check = false;
node* printInSuccessor(node* root, int val)
{
    if (root == NULL) {
        return NULL;
    }
    node* leftSide = printInSuccessor(root->left, val);
    if (leftSide != NULL) {
        return leftSide;
    }

    if (check == true) {
        check = false;
        return root;
    }

    if (root->val == val) {
        check = true;
    }

    node* rightSide = printInSuccessor(root->right, val);
    if (right != NULL) {
        return rightSide;
    }
    return NULL;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node* root = buildBst();
    int val;
    cin >> val;
    node* inSu = printInSuccessor(root, val);
    if (inSu) {
        cout << inSu->val;
    } else {
        cout << "null";
    }
    return 0;
}