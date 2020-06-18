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

node* buildTree(vector<int> in, vector<int>& post)
{
    if (in.empty()) {
        return NULL;
    }

    int mid = post.back();
    post.pop_back();
    node* root = new node(mid);
    auto itr = find(in.begin(), in.end(), mid);
    vector<int> rightIn(itr + 1, in.end());
    root->right = buildTree(rightIn, post);

    vector<int> leftIn(in.begin(), itr);
    root->left = buildTree(leftIn, post);

    return root;
}

void printPre(node* root)
{
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    printPre(root->left);
    printPre(root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> in(n, 0), post(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }

    node* root = buildTree(in, post);
    printPre(root);
    return 0;
}