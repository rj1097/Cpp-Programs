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

vector<int>::iterator max_element(vector<int>& v)
{
    auto max_itr = v.begin();
    for (auto itr = v.begin(); itr != v.end(); itr++) {
        max_itr = (*itr > *max_itr) ? itr : max_itr;
    }
    return max_itr;
}

node* build_tree(vector<int> v)
{
    if (v.size() == 0) {
        return nullptr;
    }
    auto max_itr = max_element(v);
    node* root = new node(*max_itr);
    vector<int> left_vector(v.begin(), max_itr);
    root->left = build_tree(left_vector);
    vector<int> right_vector(max_itr + 1, v.end());
    root->right = build_tree(right_vector);
    return root;
}

void print_inorder(node* root)
{
    if (root == nullptr) {
        return;
    }
    print_inorder(root->left);
    cout << root->val << " ";
    print_inorder(root->right);
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    node* root = build_tree(vec);
    print_inorder(root);
    return 0;
}