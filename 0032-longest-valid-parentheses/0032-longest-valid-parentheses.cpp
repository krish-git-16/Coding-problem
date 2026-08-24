class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int>dp(s.size(),0);
        int left=0,right=0,ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if(left==right)
            {
                ans=max(ans,left*2);
            }
            else if(right>left)
            {
                right=0;
                left=0;
            }

        }
        left=0,right=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if(left==right)
            {
                ans=max(ans,left*2);
            }
            else if(right<left)
            {
                right=0;
                left=0;
            }

        }
        return ans;
    }
    
};