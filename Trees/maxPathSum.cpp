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
    queue<node**> q;
    q.push(&root->left);
    q.push(&root->right);
    while (!q.empty()) {
        cin >> x;
        if (x != -1) {
            *q.front() = new node(x);
            q.push(&(*q.front())->left);
            q.push(&(*q.front())->right);
        }
        q.pop();
    }
    return root;
}

int maxSum = INT_MIN;
int print_sol(node* root)
{
    if (root == NULL) {
        return 0;
    }

    int leftSum = print_sol(root->left);
    int rightSum = print_sol(root->right);

    maxSum = max(maxSum, leftSum + rightSum + root->val);
    return max(0, max(leftSum, rightSum) + root->val);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node* root = buildTree();
    int sum = print_sol(root);
    cout << maxSum;
    return 0;
}