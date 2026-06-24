class Solution {
public:
    void subseq(vector<int> &nums,int index,vector<vector<int>>&ps,vector<int >&temp) {
        if(index==nums.size())
        {
            ps.push_back(temp);
            return ;
        }
        subseq(nums,index+1,ps,temp);
        temp.push_back(nums[index]);
        subseq(nums,index+1,ps,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ps;
        vector<int >temp;
        int index=0;
        subseq(nums,index,ps,temp);
        return ps;
    }
};