class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int>m(26,0);
        for(int i=0;i<n;i++)
        {
            m[s[i]-'a']++;
        }
        int p=target.size();
        string ans="";
        for(int i=0;i<p;i++)
        {
            if(m[target[i]-'a'])
            {
                ans.push_back(target[i]);
                m[target[i]-'a']--;
            }
            else
            {
                int flag=0;
                for(int j=target[i]-'a'+1;j<26;j++)
                {
                    if(m[j])
                    {
                        ans.push_back(j+'a');
                        m[j]--;
                        flag=1;
                        break;
                    }    
                }
                if (!flag) {
                    for (int b = i - 1; b >= 0; b--) {
                        for (int j = ans[b] - 'a' + 1; j < 26; j++) {
                            if (m[j]) {
                                int old = ans[b] - 'a';   
                                ans.resize(b + 1);           
                                ans[b] = j + 'a';
                                m[j]--;
                                m[old]++;                    
                                for (int k = 0; k < 26; k++)
                                    while (m[k] > 0) { ans.push_back(k + 'a'); m[k]--; }
                                return ans;
                            }
                        }
                        m[ans[b] - 'a']++;
                    }
                    return "";
                }
                for(int k=0;k<26;k++)
                {
                    while(m[k]>0)
                    {
                        ans.push_back(k+'a');
                        m[k]--; 
                    }
                }
                return ans;
            }
        }
        if (ans == target) {
            for (int i = ans.size() - 1; i >= 0; i--) {
                for (int j = ans[i] - 'a' + 1; j < 26; j++) {
                    if (m[j]) {
                        int old = ans[i] - 'a'; 
                        ans[i] = j + 'a';
                        m[j]--;
                        m[old]++;            
                        int idx = i + 1;
                        for (int k = 0; k < 26; k++)
                            while (m[k] > 0) { ans[idx++] = k + 'a'; m[k]--; }
                        return ans;
                    }
                }
                m[ans[i] - 'a']++;
            }
            return ""; 
        }
        return ans;
    }
};