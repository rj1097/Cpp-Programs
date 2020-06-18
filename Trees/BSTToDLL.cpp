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

void addNode(node*& root, int val)
{
    if (root == NULL) {
        root = new node(val);
        return;
    }

    if (val <= root->val) {
        addNode(root->left, val);
    } else {
        addNode(root->right, val);
    }
}
node* buildTree()
{
    char str[10001];
    cin.ignore();
    cin.getline(str, 10001);
    int len = strlen(str);
    str[len - 1] = '\0';

    node* root = NULL;
    char* ch = strtok(str, ", ");
    while (ch != NULL) {
        addNode(root, stoi(ch));
        ch = strtok(NULL, ", ");
    }
    return root;
}

// Recursive function to return start and end of a list
pair<node*, node*> updateRoot(node*& root)
{
    if (root == NULL) {
        return { NULL, NULL };
    }
    
    pair<node*, node*> res;
    auto leftTree = updateRoot(root->left);
    if (leftTree.second == NULL) {
        if (root->left != NULL) { //
            root->left->right = root; //
        }
    } else {
        root->left = leftTree.second;
        leftTree.second->right = root;
    }
    res.first = (leftTree.first == NULL) ? root : leftTree.first;

    auto rightTree = updateRoot(root->right);
    if (rightTree.first == NULL) {
        if (root->right != NULL) {
            root->right->left = root;
        }
    } else {
        root->right = rightTree.first;
        rightTree.first->left = root;
    }

    res.second = (rightTree.second == NULL) ? root : rightTree.second;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    node* root = buildTree();
    auto list = updateRoot(root);
    list.first->left = list.second;
    list.second->right = list.first;
    cout << '[' << list.first->val;
    for (auto itr = list.first->right; itr != list.first; itr = itr->right) {
        cout << ", " << itr->val;
    }
    cout << ']';
    return 0;
}