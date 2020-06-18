#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int data;
    node* right;
    node* left;

    node()
        : right(NULL)
        , left(NULL)
    {
    }
    node(int d)
        : right(NULL)
        , left(NULL)
    {
        this->data = d;
    }

    ~node()
    {
        if (this->left != NULL) {
            delete this->left;
        }
        if (this->right != NULL) {
            delete this->right;
        }

        delete this;
    }
};

void print_level(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        node* top = q.front();
        q.pop();
        if (top == NULL) {
            if (!q.empty()) {
                q.push(NULL);
                cout << endl;
            }
        } else {
            cout << top->data << " ";
            if (top->left) {
                q.push(top->left);
            }
            if (top->right) {
                q.push(top->right);
            }
        }
    }
}

int find_sum(node* root, int k, int& count)
{
    if (root == NULL) {
        return 0;
    }
    int currSum = find_sum(root->left, k, count);
    currSum += find_sum(root->right, k, count);
    currSum += root->data;
    if (currSum == k) {
        count++;
    }
    return currSum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        char str[1001];
        cin.ignore();
        cin.getline(str, 1001);
        char* token = strtok(str, " ");
        int num = stoi(token);
        node* root = new node(num);
        queue<node**> q;
        q.push(&root->left);
        q.push(&root->right);
        while (token != NULL) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                num = stoi(token);
                // cout << num << endl;
                *q.front() = new node(num);
                q.push(&(*q.front())->left);
                q.push(&(*q.front())->right);
                q.pop();
            }
        }
        int k;
        cin >> k;
        int count = 0;
        int sum = find_sum(root, k, count);
        cout << count << endl;
    }
    return 0;
}