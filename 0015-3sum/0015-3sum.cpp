class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        if(nums[0]>1)
        {
            return ans;
        }
        int n=nums.size();
        int start,end,sum;
        for(int i=0;i<n-2;i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) 
            continue;
            start=i+1;
            end=n-1;
            while(start<end)
            {
                sum=nums[start]+nums[end]+nums[i];
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[start],nums[end]});
                    while (start < end && nums[start] == nums[start + 1]) 
                    start++;
                    while (start < end && nums[end] == nums[end - 1]) 
                    end--;
                    start++;
                    end--;
                }
                else if(sum>0)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
        return ans;
    }
};