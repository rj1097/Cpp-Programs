#include <iostream>
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

void change(node* root)
{
    cout << "Inside function !!" << endl;
    node* root2 = root;
    cout << "Addresses :" << root << " " << root2 << endl;
    root2->val = 6;
    cout << "Values :" << root->val << " " << root2->val << endl;

    // root->next = new node(7);
    cout << "Next Addresses :" << root->next << " " << root2->next << endl;
    root2->next->val = 8;
    cout << "Next Values :" << root->next->val << " " << root2->next->val << endl;
}

node* createNode()
{
    cout << "Inside create node function !!" << endl;
    node* root = new node(5);
    node* root2 = root;
    cout << "Addresses :" << root << " " << root2 << endl;
    root2->val = 6;
    cout << "Values :" << root->val << " " << root2->val << endl;

    root->next = new node(7);
    cout << "Next Addresses :" << root->next << " " << root2->next << endl;
    root2->next->val = 8;
    cout << "Next Values :" << root->next->val << " " << root2->next->val << endl;
    return root;
}
int main()
{
    node* root = new node(5);
    node* root2 = root;
    cout << "Addresses :" << root << " " << root2 << endl;
    root2->val = 6;
    cout << "Values :" << root->val << " " << root2->val << endl;

    root->next = new node(7);
    cout << "Next Addresses :" << root->next << " " << root2->next << endl;
    root2->next->val = 8;
    cout << "Next Values :" << root->next->val << " " << root2->next->val << endl;

    change(root);
    cout << endl;
    node* root3 = createNode();
    cout << root3 << " " << root3->next;
    return 0;
}