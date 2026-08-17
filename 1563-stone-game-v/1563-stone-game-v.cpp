class Solution {
public:
    int solve(vector<int>& stoneValue,int s,int e,int sum,vector<vector<int>>&dp)
    {
        
        if(s == e)
        {
            return 0;
        }
        if(dp[s][e]!=INT_MIN)
        {
            return dp[s][e];
        }
        int l=0,r=0,ans=0;
        for(int i=s;i<e;i++)
        {
            l+=stoneValue[i];
            r=sum-l;
            if(l<r)
            {
                ans=max(ans,l+solve(stoneValue,s,i,l,dp));
            }
            else if(l==r)
            {
                ans=max(ans,max(l+solve(stoneValue,s,i,l,dp),r+solve(stoneValue,i+1,e,r,dp)));
            }
            else
            {
                ans=max(ans,r+solve(stoneValue,i+1,e,r,dp));
            }
        }
        return dp[s][e] = ans;
        
    }
    int stoneGameV(vector<int>& stoneValue) {
        int sum=0,n=stoneValue.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MIN));
        for(int i=0;i<n;i++)
        {
            sum+=stoneValue[i];
        }
        return solve(stoneValue,0,n-1,sum,dp);
    }
};