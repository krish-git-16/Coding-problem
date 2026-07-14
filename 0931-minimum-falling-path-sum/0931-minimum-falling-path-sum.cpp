class Solution {
public:
    int row[3]={-1,-1,-1};
    int col[3]={0,-1,1};
    bool valid(int r,int c,int n)
    {
        return r<n&&c<n&&r>=0&&c>=0;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++)
        { 
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<3;k++)
                {
                    if(valid(i+row[k],j+col[k],n))
                    {
                        dp[i][j]=min(dp[i][j],dp[i+row[k]][j+col[k]]);
                    }
                }
                dp[i][j]+=matrix[i][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};