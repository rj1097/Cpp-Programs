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

void print_sol(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        node* currNode = q.front();
        q.pop();
        if (currNode == NULL) {
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            if (q.front() == NULL) {
                cout << currNode->val << " ";
            }
            if (currNode->left) {
                q.push(currNode->left);
            }
            if (currNode->right) {
                q.push(currNode->right);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node* root = buildTree();
    print_sol(root);
    return 0;
}