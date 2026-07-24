class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        int first=0,second=0;
        long long sum=nums[0],ans=0;;
        while(second<n)
        {
            if(((long long)second-first+1)*sum<k)
            {
                ans+=second-first+1;
                second++;
                if(second>=n)
                break;
                sum+=nums[second];
            }
            else if(second==first)
            {
                sum-=nums[first];
                first++;
                second++;
                if(first>=n)
                break;
                sum+=nums[first];
            }
            else
            {
                sum-=nums[first];
                first++;
            }
        }
        return ans;
    }
};