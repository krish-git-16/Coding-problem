class Solution {
public:
    bool solve(string &s,string &p,int i,int j,vector<vector<int>>&dp)
    {
        if(i==0 && j==0) 
        return dp[i][j]=1;
        if(j==0)
        {
            return dp[i][j] = 0;;
        }
        if(i==0)
        {
            for(int k=j-1;k>=0;k--)
            {
                if(p[k]!='*')
                {
                    return dp[i][j] = 0;;
                }
            }
            return dp[i][j] = 1;
        }
        if(dp[i][j] != -1)
        return dp[i][j];
        if(s[i-1]==p[j-1]||p[j-1]=='?')
        {
            return dp[i][j]= solve(s,p,i-1,j-1,dp);
        }
        if(p[j-1]=='*')
        return dp[i][j]=solve(s,p,i-1,j,dp)||solve(s,p,i,j-1,dp);
        return dp[i][j]=0;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(s,p,s.size(),p.size(),dp);
    }
};