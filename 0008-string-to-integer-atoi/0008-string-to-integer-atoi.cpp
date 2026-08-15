class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        int i=0;
        bool flag=0;
        while(i < s.size()&&s[i]==' ')
        {
            i++;
        }
        if(s[i]=='-')
        {
            flag=1;
            i++;
        }
        else if(s[i]=='+')
        {
            i++;
        }
        for(;i<s.size();i++)
        {
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||s[i]==' '||s[i]=='-'||s[i]=='+'||s[i]=='.')
            {
                break;
            }
            if(ans>(INT_MAX-(s[i]-'0'))/10)
            {
                if(flag)
                return INT_MIN;
                return INT_MAX;
            }    
            ans=ans*10+(s[i]-'0');
        }
        if(flag)
        return ans*-1;
        return ans;
    }
};