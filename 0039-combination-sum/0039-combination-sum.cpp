class Solution {
public:
    void csum(int index,int target,vector<int>& candidates,vector<vector<int>>&ans,vector<int>temp)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(index==candidates.size())
        {
            return ;
        }
        
        if(target<0)
        {
            return ;
        }    
        csum(index+1,target,candidates,ans,temp);
        temp.push_back(candidates[index]);
        csum(index,target-candidates[index],candidates,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        csum(0,target,candidates,ans,temp);
        return ans;
    }
};