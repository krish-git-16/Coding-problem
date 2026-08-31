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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*prev=head;
        ListNode*cur=head->next;
        ListNode*fut=head->next->next;
        int mi=INT_MAX,ma=INT_MIN,d=0;
        int first = -1;
        int last = -1;
        while(fut)
        {
            if((prev->val<cur->val&&cur->val>fut->val)||(prev->val>cur->val&&cur->val<fut->val))
            {
                if (first == -1)
                {
                    first = d;
                }
                else
                {
                    mi=min(mi,d-last);
                }
                last=d;
            }
            cur=cur->next;
            fut=fut->next;
            prev=prev->next;
            d++;
        }
        vector<int>ans(2);
        ans[0]=mi!=INT_MAX?mi:-1;
        if(ans[0]==-1)
        {
            ans[1]=-1;
            return ans;
        }
        ans[1]=last-first;
        return ans;
    }
};