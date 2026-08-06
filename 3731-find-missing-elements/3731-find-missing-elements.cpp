class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        vector<int>arr(maxi-mini+1,0);
        for(int i=0;i<nums.size();i++)
        {
            arr[nums[i]-mini]++;
        }
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
            {
                ans.push_back(i+mini);
            }
        }
        return ans;
    }
};