class Solution {
public:
    void solve(vector<int>& candidates, int target,int index,vector<int>&temp,vector<vector<int>> &ans)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(index==candidates.size()||target<0)
        {
            return;
        }
        int next = index + 1;
        while(next < candidates.size() && candidates[next] == candidates[index])
            next++;

            temp.push_back(candidates[index]);
            solve(candidates,target-candidates[index],index+1,temp,ans);
            temp.pop_back();
            solve(candidates,target,next,temp,ans);
          

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        solve(candidates,target,0,temp,ans);
        return ans;
    }
};