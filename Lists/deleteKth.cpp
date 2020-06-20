#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int val;
    node* next;
    node()
    {
        next = nullptr;
    }
    node(int v)
        : val(v)
    {
        next = nullptr;
    }
};

node* buildList(int n)
{
    int x;
    cin >> x;
    node* root = new node(x);
    n--;
    node* currNode = root;
    while (n--) {
        cin >> x;
        currNode->next = new node(x);
        currNode = currNode->next;
    }
    return root;
}
void deleteKthNode(node* root, int n, int k)
{
    node* currNode = root;
    for (int i = 0; i < (n - k - 1); i++) {
        currNode = currNode->next;
    }
    node* toBeDeleted = currNode->next;
    currNode->next = currNode->next->next;
    delete toBeDeleted;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    node* root = buildList(n);
    deleteKthNode(root, n, k);
    for (node* currNode = root; currNode != NULL; currNode = currNode->next) {
        cout << currNode->val << " ";
    }
    return 0;
}