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

void print_result(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    vector<int> res;
    int level = 1;
    int sIdx = 0;
    int eIdx = 0;
    while (!q.empty()) {
        node* currNode = q.front();
        q.pop();
        if (currNode == NULL) {
            // cout << level << endl;
            if (!q.empty()) {
                q.push(NULL);
                if ((level % 2) == 0) {
                    // deb(res);
                    reverse(res.begin() + sIdx, res.begin() + eIdx);
                    // deb(res);
                }
                sIdx = eIdx;
                level++;
            }
        } else {
            // push val in vector;
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
    for (int i : res) {
        cout << i << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node* root = buildTree();
    print_result(root);
    return 0;
}