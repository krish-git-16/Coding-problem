class Solution {
public:
    int minAddToMakeValid(string s) {
        int flag=0,count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                flag+=1;
            }
            else
            {
                flag-=1;
            }
            if(flag<0)
            {
                count++;
                flag=0;
            }
        }
        if(flag>0)
        {
            count+=flag;
        }
        return count;
    }
};