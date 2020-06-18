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
        // node* currNode = (*q.front());
        if (x != -1) {
            *q.front() = new node(x);
            q.push(&(*q.front())->left);
            q.push(&(*q.front())->right);
        }
        q.pop();
    }
    return root;
}

void print_sol(node* root)
{
    queue<node*> q;
    q.push(root);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    node* root = buildTree();

    // node* root = buildTree(vec);
    print_sol(root);
    return 0;
}