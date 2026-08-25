class Solution {
public:
    bool checkValidString(string s) {
        int mini=0,maxi=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                mini++;
                maxi++;
            } 
            else if(s[i]==')')
            {
                maxi--;
                mini--;
                
            }
            else
            {
                maxi++;
                mini--;
            }
            if(mini<0)
            {
                mini=0;
            }
            if(maxi<0)
            return 0;
        }
        return mini==0;
    }
};