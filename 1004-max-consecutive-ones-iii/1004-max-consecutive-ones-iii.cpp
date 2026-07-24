class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int f=0,s=0,ans=0,z=0;
        while(s<nums.size())
        {
            ans=max(ans,s-f+1);
            if(z==k)
            {
                break;
            }
            else if(nums[s])
            {
                s++;
            }
            else
            {
                s++;
                z++;
            }
        }
        if(s==nums.size())
        {
            return ans;
        }
        while(s<nums.size())
        {
            
            if(nums[s])
            {
                s++;
            }
            else
            {
                while(nums[s++]);
                while(nums[f++]);
            }
            ans=max(ans,s-f+1);
        }
        return ans-1;
    }
};