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

node* buildTree(int& count)
{
    int x;
    cin >> x;
    node* root = new node(x);
    string child;
    cin >> child;
    count++;
    if (child == "true") {
        root->left = buildTree(count);
    }
    cin >> child;
    if (child == "true") {
        root->right = buildTree(count);
    }
    return root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count = 0;
    node* root = buildTree(count);
    // numNodes(root, count);
    cout << count;
    return 0;
}