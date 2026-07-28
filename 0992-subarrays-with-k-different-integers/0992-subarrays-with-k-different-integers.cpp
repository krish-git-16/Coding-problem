class Solution {
public:
    int count(vector<int>& nums, int k)
    {
        if(k<0)
        return 0;
        int f=0,s=0,n=nums.size(),diff=0,ans=0;
        unordered_map<int,int>fre;
        while(s<n)
        {
            fre[nums[s]]++;
            while(fre.size()>k)
            {
                fre[nums[f]]--;
                if(fre[nums[f]]==0)
                {
                    fre.erase(nums[f]);
                }
                f++;
            }
            ans+=s-f+1;
            s++;
        }
        return ans;
    } 
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return count(nums,k)-count(nums,k-1);
    }
};