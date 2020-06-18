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

node* buildBST()
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

void convert(node* root, int& sum)
{
    if (root == NULL) {
        return;
    }
    convert(root->right, sum);
    sum += root->val;
    root->val = sum;
    convert(root->left, sum);
}

void print_tree(node* root)
{
    if (root == NULL) {
        return;
    }
    string leftVal = (root->left) ? to_string(root->left->val) : ".";
    string rightVal = (root->right) ? to_string(root->right->val) : ".";
    cout << leftVal << "<--" << root->val << "-->" << rightVal << endl;
    print_tree(root->left);
    print_tree(root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    node* root = buildBST();
    int sum = 0;
    convert(root, sum);
    print_tree(root);
    return 0;
}