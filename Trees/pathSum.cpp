#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int val;
    node *left, *right;
    node()
    {
        left = right = NULL;
    }

    node(int d)
        : val(d)
    {
        left = right = NULL;
    }
};

node* build_tree()
{
    int x;
    cin >> x;
    node* root = new node(x);
    string next;
    cin >> next;
    if (next == "true") {
        root->left = build_tree();
    } else {
        root->left = NULL;
    }
    cin >> next;
    if (next == "true") {
        root->right = build_tree();
    } else {
        root->right = NULL;
    }

    return root;
}

bool check_sum(node* root, int k, int count = 0)
{
    if (root == NULL) {
        if (k == 0) {
            return true;
        } else {
            return false;
        }
    }
    if (k - root->val < 0) {
        return false;
    }
    return check_sum(root->left, k - root->val, count) || check_sum(root->right, k - root->val, count);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node* root = build_tree();
    int k;
    cin >> k;
    if (check_sum(root, k)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}
// 10 true 20 true 30 false false true 50 false false true 40 true 60 false false true 73 false false