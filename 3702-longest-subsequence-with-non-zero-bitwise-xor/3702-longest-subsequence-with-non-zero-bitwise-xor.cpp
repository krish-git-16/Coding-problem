class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int x=nums[0],c0=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==0)
            c0++;
            x^=nums[i];
        }
        if(!x)
        {
            if(c0==n)
            {
                return 0;
            }
            else
            {
                return n-1;
            }
        }
        return n;
        
    }
};