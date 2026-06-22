class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string s1="";
        if(n==0)
        {
            return s1;
        }
        if(n==1)
        return strs[0];
        for(int j=0;j<strs[0].size();j++)
        {
            if(strs[0][j]!=strs[1][j])
            {
                break;
            }
            s1+=strs[0][j];
        }
        if(s1.size()==0)
        {
            return s1;
        }
        if(n==2)
        {
            return s1;
        }
        int temp=0,ans=INT_MAX;
        for(int i=2;i<n;i++)
        {
            temp=0;
            for(int j=0;j<s1.size()&&j<strs[i].size();j++)
        {
            if(s1[j]!=strs[i][j])
            {
                break;
            }
            temp++;
        }
        ans=min(temp,ans);
        }
        string s2="";
        if(ans==INT_MAX)
        {
            return s1;
        }
        for(int j=0;j<ans;j++)
        {
            s2+=s1[j];
        }
        return s2;
    }
};