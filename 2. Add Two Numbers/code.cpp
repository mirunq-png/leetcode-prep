#include <iostream>
using namespace std;

  //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1; // pt parcurs l1
        ListNode* p2=l2;
        ListNode* sol=new ListNode(0);
        ListNode* crt=sol;
        int carry=0;
        while (p1!=nullptr||p2!=nullptr)
        {
            int val1=0, val2=0;
            if (p1!=nullptr)
                {
                    val1=p1->val;
                    p1=p1->next; // urm nod
                }
            if (p2!=nullptr)
                {
                    val2=p2->val;
                    p2=p2->next; // idem
                }
            int s=val1+val2+carry;
            crt->next=new ListNode(s%10);
            crt=crt->next;
            carry=s/10;
        }
        if (carry!=0) // cazul in care am parcurs listele si a mai ramas o unitate
        {
            crt->next=new ListNode(1);
        }
        return sol->next;
    }
};
int main()
{

    return 0;
}