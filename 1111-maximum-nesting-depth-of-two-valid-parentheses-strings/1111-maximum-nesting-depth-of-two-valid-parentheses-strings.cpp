class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int>ans;
        bool mem=0;
        for(int i=0;i<n;i++)
        {
            if(seq[i]=='(')
            {
                ans.push_back(mem);
                mem=!mem;
            }
            else
            {
                mem=!mem;
                ans.push_back(mem);
            }
        }
        return ans;
    }
};