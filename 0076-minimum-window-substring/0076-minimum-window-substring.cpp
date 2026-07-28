class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>fre;
        int k=0;
        for(int i=0;i<t.size();i++)
        {
            k++;
            fre[t[i]]++;
        }
        int count=0;
        int f=0,l=0;
        int start=0,len=INT_MAX;
        while(l<s.size())
        {
            if(fre[s[l]]>0)
            {
                count++;
            }
            fre[s[l]]--;
            while(count==k)
            {
                fre[s[f]]++;
                if(fre[s[f]]>0)
                count--;
                if (l-f+1<len)
                {
                    start = f;
                    len = l - f + 1;
                }
                f++;
            }
            l++;
        }
        if(len==INT_MAX)
        return "";
        return s.substr(start,len);
    }
};