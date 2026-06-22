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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string num1,num2;
        while(l1)
        {
            num1+=l1->val;
            l1=l1->next;
        }
        while(l2)
        {
            num2+=l2->val;
            l2=l2->next;
        }
        string num;
        int i=0,j=0,carry=0;
        if(num1.size()<num2.size())
        {
            swap(num1,num2);
        }
        while(j<num2.size())
        {
            num.push_back((num1[i]+num2[j]+carry)%10);
            carry=(num1[i]+num2[j]+carry)/10;
            i++;
            j++;
        }
        while(i<num1.size())
        {
            num.push_back((num1[i]+carry)%10);
            carry=(num1[i]+carry)/10;
            i++;
        }
        if(carry>0)
        {
            num.push_back(1);
        }
        ListNode*head=NULL,*prev=NULL,*temp=NULL;
        for(int k=0;k<num.size();k++)
        {
            if(head==NULL)
            {
                head=new ListNode(num[k]);
                prev=head;
            }
            else
            {
                temp=new ListNode(num[k]);
                prev->next=temp;
                prev=temp;
            }
        }
        return head;
    }
};