class Solution {
public:
    string sortVowels(string s) {
        vector<int>upper(26,0);
        vector<int>lower(26,0);
        string so;
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                lower[s[i]-'a']+=1;
            }
            else if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                upper[s[i]-'A']++;
            }
        }
        for(int i=0;i<26;i++)
        {
             char c='A'+i;
             while(upper[i])
             {
                so+=c;
                upper[i]--;
             }
        }
        for(int i=0;i<26;i++)
        {
             char c='a'+i;
             while(lower[i])
             {
                so+=c;
                lower[i]--;
             }
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                s[i]=so[k];
                k++;
            }
        }
    return s;
    }
};