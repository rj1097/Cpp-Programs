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

node* buildList()
{
    int n;
    cin >> n;
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

node* swapNodes(node* root)
{
    if (root == NULL) {
        return NULL;
    }
    if (root->next == NULL) {
        return root;
    }
    node* nextPair = root->next->next;
    node* firstNode = root->next;
    firstNode->next = root;
    firstNode->next->next = swapNodes(nextPair);
    // }
    return firstNode;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node* root = buildList();
    for (node* currNode = root; currNode != NULL; currNode = currNode->next) {
        cout << currNode->val << " -> ";
    }
    root = swapNodes(root);
    cout << endl;
    for (node* currNode = root; currNode != NULL; currNode = currNode->next) {
        cout << currNode->val << " -> ";
    }
    return 0;
}