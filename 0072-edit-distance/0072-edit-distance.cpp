class Solution {
public:
    // int solve(string &w1,string &w2,int i,int j,vector<vector<int>>&dp)
    // {
    //     if(i<0)
    //     {
    //         return j+1;
    //     }
    //     if(j<0)
    //     {
    //         return i+1;
    //     }
    //     if(dp[i][j]!=-1)
    //     {
    //         return dp[i][j];
    //     }
    //     if(w1[i]==w2[j])
    //     {
    //         return dp[i][j]=solve(w1,w2,i-1,j-1,dp);
    //     }
    //     return dp[i][j]=min(1+solve(w1,w2,i-1,j-1,dp),min(1+solve(w1,w2,i,j-1,dp),1+solve(w1,w2,i-1,j,dp)));
    // }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return solve(word1,word2,n-1,m-1,dp);
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=i;
        }
        for(int i=1;i<=m;i++)
        {
            dp[0][i]=i;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                dp[i][j]=dp[i-1][j-1];
                else
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
            }
        }
        return dp[n][m];
    }
};