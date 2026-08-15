class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(string s:strs)
        {
            vector<int>fre(26,0);
            string t;
            for(int i=0;i<s.size();i++)
            {
                fre[s[i]-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                t+=to_string(fre[i])+'#';
            }
            m[t].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto &s:m)
        {
            ans.push_back(s.second);
        }
        return ans;
    }
};