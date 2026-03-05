#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v; // punem lista in vector
        ListNode* crt = head;
        while (crt != nullptr) 
        {
            v.push_back(crt->val);
            crt = crt->next;
        }
        return buildTree(v, 0, v.size() - 1);
    }
    TreeNode* buildTree(vector<int>& v, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mij = left + (right - left) / 2;
        TreeNode* rad = new TreeNode(v[mij]);
        rad->left = buildTree(v, left, mij - 1);
        rad->right = buildTree(v, mij + 1, right);
        return rad;
    }
};

int main()
{
    return 0;
}