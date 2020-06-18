#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int val;
    node *parent, *leftChild, *rightChild;

    node()
    {
        parent = leftChild = rightChild = nullptr;
    }

    node(int d)
        : val(d)
    {
        parent = leftChild = rightChild = nullptr;
    }
};

void addNode(node*& root, node* parent, int x)
{
    if (root == NULL) {
        root = new node(x);
        root->parent = parent;
        return;
    }
    if (x <= root->val) {
        addNode(root->leftChild, root, x);
    } else {
        addNode(root->rightChild, root, x);
    }
}

node* buildBST()
{
    int n;
    cin >> n;
    node* root = NULL;
    while (n--) {
        int x;
        cin >> x;
        addNode(root, NULL, x);
    }
    return root;
}

node* searchNode(node* root, int val)
{
    if (root == NULL) {
        return NULL;
    }
    if (root->val == val) {
        return root;
    }
    node* left = searchNode(root->leftChild, val);
    if (left) {
        return left;
    }

    node* right = searchNode(root->rightChild, val);
    return right;
}

node* inOrderSuccessor(node* root)
{
    if (root->rightChild) {
        root = root->rightChild;
        while (root->leftChild) {
            root = root->leftChild;
        }
        return root;
    }
    while (root->parent && root->parent->leftChild != root) {
        root = root->parent;
    }
    return root->parent;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node* root = buildBST();
    int num;
    cin >> num;
    node* nodeNum = searchNode(root, num);
    node* inSu = inOrderSuccessor(nodeNum);
    if (inSu != NULL) {
        cout << inSu->val;
    } else {
        cout << "null";
    }
    return 0;
}