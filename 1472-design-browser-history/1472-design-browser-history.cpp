class Node{
    public:
    string data;
    Node* next;
    Node* prev;
    Node(string data)
    {
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
class BrowserHistory {
public:
    Node* curr;
    BrowserHistory(string homepage) {
        Node* node=new Node(homepage);
        curr=node;
    }
    
    void visit(string url) {
        Node*temp=curr->next;
        curr->next=NULL;
        while(temp)
        {
            Node*copy=temp;
            temp=temp->next;
            delete copy;
        }
        Node* node=new Node(url);
        curr->next=node;
        node->prev=curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(steps--&&curr->prev)
        {
            curr=curr->prev;
        }
        return curr->data;
    }
    
    string forward(int steps) {
        while(steps--&&curr->next)
        {
            curr=curr->next;
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */