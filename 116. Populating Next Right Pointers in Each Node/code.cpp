#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root==0)
            return nullptr;
        Node* l=root;
        while (l->left)
        {
            Node* crt=l;
            while (crt)
            {
                crt->left->next=crt->right;
                if (crt->next)
                    crt->right->next=crt->next->left;
                crt=crt->next;
            }
            l=l->left;
        }
        return root;
    }
};

int main()
{
    return 0;
}