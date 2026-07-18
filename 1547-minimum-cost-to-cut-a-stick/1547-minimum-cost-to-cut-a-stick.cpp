class Solution {
public:
    int solve(int n,vector<int>&cuts,int i,int j,vector<vector<int>>&dp)
    {
        if(i==j)
        {
            return 0;
        }
        int mini=INT_MAX;
        if(dp[i][j]!=-1)
        return dp[i][j];
        for(int k=i;k<=j;k++)
        {
            int cost=cuts[j+1]-cuts[i-1]+solve(n,cuts,i,k-1,dp)+solve(n,cuts,k+1,j,dp);
            mini=min(cost,mini);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size() - 2;
        vector<vector<int>>dp(m+2,vector<int>(m+2,0));
        // return solve(n,cuts,1,cuts.size()-2,dp);
        for(int i=m;i>=1;i--)
        {
            for(int j=i;j<=m;j++)
            {
                int mini=INT_MAX;
                for(int k=i;k<=j;k++)
                {
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(cost,mini);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][m];
    }
};