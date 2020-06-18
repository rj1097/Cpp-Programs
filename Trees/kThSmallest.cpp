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

node* buildBST()
{
    char str[10001];
    cin.ignore();
    cin.getline(str, 10001);
    int len = strlen(str);
    str[len - 1] = '\0';
    queue<node**> q;
    if (str[0] == 'N') {
        return NULL;
    }
    char* ch = strtok(str, ",");
    node* root = new node(stoi(ch));

    q.push(&root->left);
    q.push(&root->right);
    while (!q.empty()) {
        ch = strtok(NULL, ",");
        if (ch != NULL && ch[0] != 'N' && ch[0] != 'n') {
            *q.front() = new node(stoi(ch));
            q.push(&(*q.front())->left);
            q.push(&(*q.front())->right);
        }
        q.pop();
    }
    return root;
}

int kThElement(node* root, int& n)
{
    if (root == NULL) {
        return -1;
    }
    int ans = kThElement(root->left, n);
    n--;
    if (ans == -1) {
        if (n == 0) {
            ans = root->val;
        } else {
            ans = kThElement(root->right, n);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node* root = buildBST();
    int n;
    cin >> n;
    int kTh = kThElement(root, n);
    cout << kTh;
    return 0;
}