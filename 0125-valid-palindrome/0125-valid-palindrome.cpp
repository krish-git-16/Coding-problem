class Solution {
public:
    bool isPalindrome(string s) {
        string s2;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>=65&&s[i]<=90)
            {
                s[i]=s[i]+32;
                s2+=s[i];
            }
            else if((s[i]>=97&&s[i]<=122)||(s[i]>=48&&s[i]<=57))
            {
                s2+=s[i];
            }
        }
        int f=0,l=s2.size()-1;
        while(f<l)
        {
            if(s2[f]!=s2[l])
            {
                return 0;
            }
            f++;
            l--;
        }
        return 1;
    }
};