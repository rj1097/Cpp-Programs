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

node* updateTree(node* root, int x, int d)
{
    queue<node*> q;
    if (d == 1) {
        node* newRoot = new node(x);
        newRoot->left = root;
        return newRoot;
    }
    q.push(root);
    q.push(NULL);
    int level = 1;
    while (!q.empty()) {
        node* currNode = q.front();
        q.pop();
        if (currNode == NULL) {
            if (!q.empty()) {
                q.push(NULL);
                level++;
            }
            if (level == d) {
                break;
            }
        } else {
            if (level == (d - 1)) {
                node* left = new node(x);
                node* right = new node(x);
                if (currNode->left) {
                    left->left = currNode->left;
                }

                if (currNode->right) {
                    right->right = currNode->right;
                }
                currNode->left = left;
                currNode->right = right;
            } else {
                if (currNode->left) {
                    q.push(currNode->left);
                }

                if (currNode->right) {
                    q.push(currNode->right);
                }
            }
        }
    }
    return root;
}

void print_sol(node* root)
{
    if (root == NULL) {
        return;
    }

    if (root->left != NULL) {
        cout << root->left->val;
    }
    cout << " <- " << root->val << " -> ";
    if (root->right != NULL) {
        cout << root->right->val;
    }
    cout << endl;
    print_sol(root->left);
    print_sol(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node* root = buildTree();
    int x, d;
    cin >> x >> d;
    root = updateTree(root, x, d);
    print_sol(root);
    return 0;
}