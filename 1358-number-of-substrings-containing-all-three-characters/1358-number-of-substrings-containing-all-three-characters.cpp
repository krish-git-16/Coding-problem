class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>alpha(3,0);
        int l=0,f=0,n=s.size(),diff=0,ans=0;
        while(l<n)
        {
            if(alpha[s[l]-'a']==0)
            diff++;
            alpha[s[l]-'a']++;
            while(diff==3)
            {
                ans+=n-l;
                alpha[s[f]-'a']--;
                if(alpha[s[f]-'a']==0)
                diff--;
                f++;
            }
            l++;
            
        }
        return ans;
    }
};