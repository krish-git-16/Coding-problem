/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        Node* copy=NULL;
        if(!temp)
        return NULL;
        if(!temp->next)
        {
            if(!temp->next)
            {
                Node* node = new Node(temp->val);
                node->random = (temp->random ? node : NULL);
                return node;
            }
        }
        while(temp)
        {
            Node* node=new Node(temp->val);
            copy=temp->next;
            temp->next=node;
            node->next=copy;
            temp=copy;
        }
        temp=head;
        while(temp)
        {
            if(temp->random)
            temp->next->random = temp->random->next;
            else
            temp->next->random = NULL;
            temp=temp->next->next;
        }
        temp=head;
        Node*head1=head->next;
        Node*copytemp=temp->next;
        while(temp)
        {
            temp->next=copytemp->next;
            temp=temp->next;
            if(temp)
            {
                copytemp->next=temp->next;
                copytemp=copytemp->next;;
            }
        }
        return head1;
    }
};