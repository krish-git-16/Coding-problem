class Solution {
public:
    int find(int row ,int col,vector<vector<int>>& matrix,vector<vector<int>>&dp,int n ,int m)
    {
        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        dp[row][col] = 1;
        if(row-1>=0&&matrix[row-1][col]>matrix[row][col])
        {
            dp[row][col]=max(dp[row][col],1+find(row-1,col,matrix,dp,n,m));
        }    
        if(row+1<m&&matrix[row+1][col]>matrix[row][col])
        {
            dp[row][col]=max(dp[row][col],1+find(row+1,col,matrix,dp,n,m));
        }    
        if(col+1<n&&matrix[row][col+1]>matrix[row][col])
        {
            dp[row][col]=max(dp[row][col],1+find(row,col+1,matrix,dp,n,m));
        }    
        if(col-1>=0&&matrix[row][col-1]>matrix[row][col])
        {
            dp[row][col]=max(dp[row][col],1+find(row,col-1,matrix,dp,n,m));  
        }      
        return dp[row][col]; 
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                find(i,j,matrix,dp,n, m);
            }
        }
        int ans=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};