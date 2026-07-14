class Solution {
public:
    int row[2]={0,-1};
    bool valid(int c,int n)
    {
        return c<n&&c>=0;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp;
        dp.push_back({triangle[0][0]});
        for(int i=1;i<n;i++)
        {
            vector<int>temp;
            for(int j=0;j<triangle[i].size();j++)
            {
                int  t=INT_MAX;
                for(int k=0;k<2;k++)
                {
                    if(valid(j+row[k],i))
                    {
                        t=min(dp[i-1][j+row[k]],t);
                    }
                }
                temp.push_back(t+triangle[i][j]);
            }
            dp.push_back(temp);
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(dp[n-1][i],ans);
        }
        return ans;
    }
};