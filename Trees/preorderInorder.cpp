#include <bits/stdc++.h>
#define deb(vec)          \
    cout << #vec << ": "; \
    for (auto i : vec) {  \
        cout << i << " "; \
    }                     \
    cout << endl;

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

node* buildTree(vector<int>& pre, vector<int> in)
{
    if (in.empty()) {
        return NULL;
    }

    int mid = pre.front();
    pre.erase(pre.begin());
    // deb(pre);
    node* root = new node(mid);

    auto midItr = find(in.begin(), in.end(), mid);
    vector<int> leftTree(in.begin(), midItr);
    root->left = buildTree(pre, leftTree);

    vector<int> rightTree(midItr + 1, in.end());
    root->right = buildTree(pre, rightTree);
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    vector<int> pre(n, 0), in(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> in[i];
    }
    // deb(in);

    node* root = buildTree(pre, in);
    printTree(root);
    return 0;
}