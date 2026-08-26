class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int f=0,e=0;
        int length=INT_MAX,ind=-1;
        while(e<n)
        {
            if(s[e]=='1')
            k--;
            while(k==0)
            {
                if(length>e-f+1)
                {
                    length=e-f+1;
                    ind=f;
                }
                if(length==e-f+1)
                {
                    if(s.substr(ind,length)>s.substr(f,length))
                    ind=f;
                }
                if(s[f]=='1')
                k++;
                f++;
            }
            e++;
        }
        if(ind==-1)
        return "";
        return s.substr(ind,length);
    }
};