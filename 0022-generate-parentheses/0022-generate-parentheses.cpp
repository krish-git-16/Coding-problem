class Solution {
public:
    void para(vector<string> &v,int n,string &s,int open ,int close)
    {   
        if(s.size()==2*n)
        {
            v.push_back(s);
            return;
        }    
        if(open<n)
        {
            s+='(';
             para(v,n,s,open+1,close);
             s.pop_back();
        }    
        if(open>close)
        {
            s+=')';
            para(v,n,s,open,close+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int index=0;
        vector<string> v;
        string s;
        para(v,n,s,0,0);
        return v;
    }
};