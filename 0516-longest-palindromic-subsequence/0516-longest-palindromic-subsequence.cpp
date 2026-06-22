class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2;
        for(int i=s.size()-1;i>=0;i--)
        {
            s2+=s[i];
        }
        int n=s.size();
        vector<int>dp(n+1,0);
        int prev,curr;
        for(int i=1;i<=n;i++)
        {
            prev=0;
            curr=0;
            for(int j=1;j<=n;j++)
            {
                prev=curr;
                curr=dp[j];
                if(s[i-1]==s2[j-1])
                {
                    dp[j]=1+prev;
                }
                else
                {
                    dp[j]=max(dp[j],dp[j-1]);
                }
            }
        }
        return dp[n];
    }
};