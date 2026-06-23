/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*temp=head,*copy=head;
        if(!head)
        {
            return NULL;
        }
        while(temp->next)
        {
            if(temp->next->val==temp->val)
            {
                copy=temp->next;
                temp->next=copy->next;
                copy->next=NULL;
                delete copy;
            }
            else
            {
                temp=temp->next;
            }
            
        }
        return head;
    }
};