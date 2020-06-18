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

// bool check_equality(node* root1, node* root2)
// {
//     if (root1 == nullptr || root2 == nullptr) {
//         return (root2 == nullptr) && (root1 == nullptr);
//     }
//     return (root1->val == root2->val) && (check_equality(root1->left, root2->right) && check_equality(root1->right, root2->left));
// }
bool is_equal(node* left, node* right)
{
    if (left == nullptr || right == nullptr) {
        return (left == nullptr) && (right == nullptr);
    }
    return (left->val == right->val) && (is_equal(left->left, right->right) && is_equal(left->right, right->left));
}
// void solve()
// {
//     int x;
//     cin >> x;
//     queue<node**> q1, q2;
//     node* root1 = new node(x);
//     node* root2 = new node(x);
//     q1.push(&(root1->left));
//     q1.push(&(root1->right));

//     q2.push(&(root2->right));
//     q2.push(&(root2->left));

//     while (!q1.empty()) {
//         cin >> x;
//         if (x != -1) {
//             *q1.front() = new node(x);
//             *q2.front() = new node(x);
//             q1.push(&((*q1.front())->left));
//             q1.push(&((*q1.front())->right));

//             q2.push(&((*q2.front())->right));
//             q2.push(&((*q2.front())->left));
//         }
//         q1.pop();
//         q2.pop();
//     }
//     bool ans = check_equality(root1, root2);
//     if (ans) {
//         cout << "YES";
//     } else {
//         cout << "NO";
//     }
// }

node* build_tree()
{
    int x;
    cin >> x;
    if (x == -1) {
        return nullptr;
    }
    queue<node**> q1;
    node* root = new node(x);
    q1.push(&(root->left));
    q1.push(&(root->right));

    while (!q1.empty()) {
        cin >> x;
        if (x != -1) {
            *q1.front() = new node(x);
            q1.push(&((*q1.front())->left));
            q1.push(&((*q1.front())->right));
        }
        q1.pop();
    }
    return root;
}
int main()
{
    node* root = build_tree();
    bool ans = false;
    if (root == nullptr) {
        ans = true;
    } else {
        ans = (is_equal(root->left, root->right));
    }
    if (ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}