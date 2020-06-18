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

void printTree(node* root)
{
    if (root == NULL) {
        return;
    }
    if (root->left != NULL) {
        cout << root->left->val << " => ";
    } else {
        cout << "END => ";
    }
    cout << root->val;

    if (root->right != NULL) {
        cout << " <= " << root->right->val;
    } else {
        cout << " <= END";
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

void print_sol(node* root)
{
    if (root == NULL) {
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    vector<int> res;
    int sIdx = 0, eIdx = 0;
    while (!q.empty()) {
        node* currNode = q.front();
        q.pop();
        if (currNode == NULL) {
            if (!q.empty()) {
                q.push(NULL);
            }
            cout << *max_element(res.begin() + sIdx, res.begin() + eIdx) << " ";
            sIdx = eIdx;
        } else {
            res.push_back(currNode->val);
            eIdx++;
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
    // printTree(root);

    print_sol(root);
    return 0;
}