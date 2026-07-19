class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size(),ans=0;
        int start=1,end=*max_element(nums.begin(),nums.end());
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=(nums[i]%mid)?nums[i]/mid+1:nums[i]/mid;
            }
            if(sum<=threshold)
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
};