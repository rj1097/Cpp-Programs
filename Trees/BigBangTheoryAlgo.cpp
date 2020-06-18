#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node()
    {
        left = right = NULL;
    }
    node(int d)
    {
        left = right = NULL;
        data = d;
    }
};

node* build_tree(int& t_nodes)
{
    if (t_nodes == 0) {
        return NULL;
    }
    t_nodes--;
    int x;
    cin >> x;
    if (x == -1) {
        return NULL;
    } else {
        node* root = new node(x);
        root->left = build_tree(t_nodes);
        root->right = build_tree(t_nodes);
        return root;
    }
}

node* find_node(node* root, int d)
{
    if (root == NULL) {
        return NULL;
    }
    if (root->data == d) {
        return root;
    }
    node* left = find_node(root->left, d);
    if (left == NULL) {
        node* right = find_node(root->right, d);
        return right;
    } else {
        return left;
    }
}

int total_nodes(node* root)
{
    if (root == NULL) {
        return 0;
    }

    int sum = 1;
    sum += total_nodes(root->left);
    sum += total_nodes(root->right);
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t_nodes, a_nodes, m_node;
    vector<int> nodes;
    cin >> t_nodes;
    cin >> a_nodes;
    cin >> m_node;
    // cout << t_nodes << " " << a_nodes << " " << m_node;
    node* root = build_tree(t_nodes);
    node* rajeshNode = find_node(root, m_node);
    int ans = 0;

    int total_rajesh_nodes = total_nodes(rajeshNode);
    if (total_rajesh_nodes <= (a_nodes - total_rajesh_nodes)) {
        ans = 1;
    } else {
        int total_right_nodes = total_nodes(rajeshNode->right);
        if (total_right_nodes >= (a_nodes - total_right_nodes)) {
            ans = 1;
        } else {
            int total_left_nodes = total_nodes(rajeshNode->left);
            if (total_left_nodes >= (a_nodes - total_left_nodes)) {
                ans = 1;
            }
        }
    }

    cout << ans;
    return 0;
}