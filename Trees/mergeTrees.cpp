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

node* buildTree(char* str)
{
    // cin.get();
    // cout << str << endl;
    char* ch = strtok(str, " ");
    queue<node**> q;
    node* root = NULL;
    if (ch[0] != 'N') {
        root = new node(stoi(ch));
    } else {
        return NULL;
    }

    q.push(&root->left);
    q.push(&root->right);

    while (!q.empty()) {

        ch = strtok(NULL, " ");
        if (ch != NULL && ch[0] != 'N') {
            int val = stoi(ch);
            *q.front() = new node(val);
            q.push(&(*q.front())->left);
            q.push(&(*q.front())->right);
        }
        q.pop();
    }
    return root;
}

void inOrder(node* root, vector<int>& vec)
{
    if (root == NULL) {
        return;
    }

    inOrder(root->left, vec);
    vec.push_back(root->val);
    inOrder(root->right, vec);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    char str1[100001], str2[100001];
    cin.getline(str1, 100001);
    // cin.ignore();
    cin.getline(str2, 100001);

    // cout << str1 << endl;
    // cout << str2 << endl;
    node* root1 = buildTree(str1);
    node* root2 = buildTree(str2);

    vector<int> vec1, vec2, res;
    inOrder(root1, vec1);
    inOrder(root2, vec2);

    int ptr1 = 0, ptr2 = 0;

    while (ptr1 < vec1.size() && ptr2 < vec2.size()) {
        if (vec1[ptr1] < vec2[ptr2]) {
            res.push_back(vec1[ptr1++]);
        } else {
            res.push_back(vec2[ptr2++]);
        }
    }

    while (ptr1 < vec1.size()) {
        res.push_back(vec1[ptr1++]);
    }

    while (ptr2 < vec2.size()) {
        res.push_back(vec2[ptr2++]);
    }

    for (int i : res) {
        cout << i << " ";
    }
    return 0;
}