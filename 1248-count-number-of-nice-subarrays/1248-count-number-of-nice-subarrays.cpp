class Solution {
public:
    int count(vector<int>& nums, int k)
    {
        if(k<0)
        return 0;
        int f=0,s=0,n=nums.size();
        int c_odd=0,ans=0;
        while(s<n)
        {
            if(nums[s]%2)
            c_odd++;
            while(c_odd>k)
            {
                if(nums[f]%2)
                c_odd--;
                f++;
            }
            ans+=(s-f+1);
            s++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums,k)-count(nums,k-1);
    }
};