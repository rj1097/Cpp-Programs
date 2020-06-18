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

    node(int d)
        : val(d)
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
    n--;
    node* root = new node(x);
    node* currNode = root;
    while (n--) {
        cin >> x;
        currNode->next = new node(x);
        currNode = currNode->next;
    }

    return root;
}

void print_sol(node* root)
{
    cout << "Original List: ";
    node* currNode = root;
    while (currNode != NULL) {
        cout << currNode->val << " ";
        currNode = currNode->next;
    }
    node *oddH = NULL, *evenH = NULL, *oddT = NULL, *evenT = NULL;
    currNode = root;
    bool isOdd = true;
    while (currNode != NULL) {
        if (isOdd) {
            if (oddH == NULL) {
                oddH = currNode;
                oddT = currNode;
            } else {
                oddT->next = currNode;
                oddT = currNode;
            }
            isOdd = false;
        } else {
            if (evenH == NULL) {
                evenH = currNode;
                evenT = currNode;
            } else {

                evenT->next = currNode;
                evenT = currNode;
            }
            isOdd = true;
        }
        currNode = currNode->next;
    }
    oddT->next = evenH;
    currNode = root;
    cout << endl;
    cout << "Modified List: ";
    while (currNode != NULL) {
        cout << currNode->val << " ";
        currNode = currNode->next;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    node* root = buildList();
    print_sol(root);
    return 0;
}