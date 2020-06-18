#include <bits/stdc++.h>

using namespace std;

#define deb(vec)          \
    cout << #vec << ": "; \
    for (auto i : vec) {  \
        cout << i << " "; \
    }                     \
    cout << endl;

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

void find_paths(node* root, int n, int& count)
{
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        if (n == root->val) {
            count++;
        }
        return;
    }
    find_paths(root->left, n - root->val, count);
    find_paths(root->right, n - root->val, count);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    node* root = buildTree();
    int n;
    cin >> n;
    int count = 0;
    find_paths(root, n, count);
    cout << count;
    return 0;
}