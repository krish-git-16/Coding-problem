class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>m;
        int n=fruits.size(),f=0,s=0,ans=0;
        while(s<n)
        {
            m[fruits[s]]++;
            while(m.size()>2)
            {
                if(m[fruits[f]])
                {
                    m[fruits[f]]--;
                    if(m[fruits[f]]==0)
                    m.erase(fruits[f]);
                    f++;
                }
            }
            s++;
            ans=max(ans,s-f);
        }
        return ans;
    }
};