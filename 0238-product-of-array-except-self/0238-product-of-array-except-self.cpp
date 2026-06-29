class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int temp=1;
        int flag=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                temp*=nums[i];
            }
            else
            {
                flag++;
            }
        }
        if(flag>1)
        {
            return ans;
        }
        if(flag==1)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==0)
                {
                    ans[i]=temp;
                }
            }
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                ans[i]=temp/nums[i];
            }
        }
        return ans;
    }
};