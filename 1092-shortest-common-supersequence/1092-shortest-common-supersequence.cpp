class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(),m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=n,j=m;
        vector<int>stri;
        vector<int>strj;
        while(i>0&&j>0)
        {
            if(dp[i][j]==dp[i-1][j])
            {
                i--;
            }
            else if(dp[i][j]==dp[i][j-1])
            {
                j--;
            }
            else
            {
                i--;
                j--;
                stri.push_back(i);
                strj.push_back(j);
            }
        }
        if(stri.empty())
{
    return str1 + str2;
}
        reverse(stri.begin(),stri.end());
        reverse(strj.begin(),strj.end());
        
        string ans;
        for(int i=0;i<stri[0];i++)
        {
            ans+=str1[i];
        }
        for(int i=0;i<strj[0];i++)
        {
            ans+=str2[i];
        }
        for(int i=0;i<stri.size()-1;i++)
        {
            ans+=str1[stri[i]];
            for(int j=stri[i]+1;j<stri[i+1];j++)
            {
                ans+=str1[j];
            }
            for(int j=strj[i]+1;j<strj[i+1];j++)
            {
                ans+=str2[j];
            }
        }
        ans+=str1[stri[stri.size()-1]];
        for(int i=stri[stri.size()-1]+1;i<str1.size();i++)
        {
            ans+=str1[i];
        }
        for(int i=strj[strj.size()-1]+1;i<str2.size();i++)
        {
            ans+=str2[i];
        }
        return ans;
    }
};