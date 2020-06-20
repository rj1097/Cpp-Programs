#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int val;
    node* next;
    node* random;
    node()
    {
        next = random = nullptr;
    }

    node(int d)
        : val(d)
    {
        next = random = nullptr;
    }
};

node* buildList()
{
    int n;
    cin >> n;
    unordered_map<int, node*> lookup;
    vector<int> random;
    node *root = NULL, *currNode = NULL;
    vector<int> randomVec;
    int x, y;
    cin >> x >> y;
    randomVec.push_back(y);
    root = currNode = new node(x);
    lookup[0] = root;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        randomVec.push_back(y);
        currNode->next = new node(x);
        currNode = currNode->next;
        lookup[i] = currNode;
    }
    currNode = root;
    for (int i = 0; i < n; i++) {
        currNode->random = lookup[randomVec[i]];
        currNode = currNode->next;
    }
    return root;
}

node* deepCopy(node* root)
{
    for (node* currNode = root;;) {
        node* newNode = new node(currNode->val);
        newNode->next = currNode->next;
        currNode->next = newNode;
        if (currNode->next->next == NULL) {
            break;
        }
        currNode = currNode->next->next;
    }

    for (node* currNode = root;;) {
        if (currNode->random) {
            currNode->next->random = currNode->random->next;
        }
        if (currNode->next->next == NULL) {
            break;
        }
        currNode = currNode->next->next;
    }

    node* newRoot = root->next;
    for (node *currNode = root, *newCurrNode = newRoot;;) {

        currNode->next = currNode->next->next;
        newCurrNode->next = newCurrNode->next->next;
        currNode = currNode->next;
        newCurrNode = newCurrNode->next;
        if (newCurrNode->next == NULL) {
            currNode->next = NULL;
            break;
        }
    }
    return newRoot;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    node* root = buildList();
    node* rootCopy = deepCopy(root);
    cout << "Old List: ";
    for (node* currNode = root; currNode != NULL;) {
        cout << "(" << currNode->val << ", ";
        if (currNode->random) {
            cout << currNode->random->val;
        } else {
            cout << "null";
        }
        cout << ") ";
        currNode = currNode->next;
    }
    cout << endl;
    cout << "Copied List: ";
    for (node* currNode = rootCopy; currNode != NULL;) {
        cout << "(" << currNode->val << ", ";
        if (currNode->random) {
            cout << currNode->random->val;
        } else {
            cout << "null";
        }
        cout << ") ";
        currNode = currNode->next;
    }
    return 0;
}