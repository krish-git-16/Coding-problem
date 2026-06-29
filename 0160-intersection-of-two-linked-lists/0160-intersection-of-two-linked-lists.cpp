/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *h1=headA,*h2=headB;
        int c1=0,c2=0;
        while(h1)
        {
            h1=h1->next;
            c1++;
        }
        while(h2)
        {
            h2=h2->next;
            c2++;
        }
        if(c1>c2)
        {
            c1=c1-c2;
            while(c1--)
            {
                headA=headA->next;
            }   
        }
        else
        {
            c2=c2-c1;
            while(c2--)
            {
                headB=headB->next;
            }   
        }
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};