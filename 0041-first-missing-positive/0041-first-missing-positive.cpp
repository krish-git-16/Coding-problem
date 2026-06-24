class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0||nums[i]>n)
            {
                nums[i]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]%(n+1)!=0)
            {
                nums[(nums[i]%(n+1))-1]+=n+1;
            }
        }
        int ans=n+1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]/(n+1)==0)
            {
                return i+1;
            }
        }
        return ans;
    }
};