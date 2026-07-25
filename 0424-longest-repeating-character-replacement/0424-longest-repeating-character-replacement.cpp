class Solution {
public:
    int characterReplacement(string s, int k) {
        int f=0,l=0,n=s.size(),mf=0,ans=0;
        vector<int>alpha(26,0);
        while(l<n)
        {
            alpha[s[l]-'A']++;
            mf=*max_element(alpha.begin(),alpha.end());
            while(l-f+1-mf>k)
            {
                alpha[s[f]-'A']--;
                f++;
            }
            ans=max(ans,l-f+1);
            l++;
        }
        return ans;
    }
};