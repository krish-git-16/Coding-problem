class Solution {
public:
    int count(vector<int>nums,int goal)
    {
        int first=0,second=0,ans=0,n=nums.size(),sum=0;
        if(goal<0)
        return 0;
        while(second<n)
        {
            sum+=nums[second];
            int temp=0;
            while(sum>goal)
            {
                sum-=nums[first];
                first++;
            }
            ans+=second-first+1;
            second++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return count(nums,goal)-count(nums,goal-1);
    }
};