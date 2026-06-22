class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,right=n-1;
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int >temp(4,0);
        for(int i=0;i<n-3;i++)
        {
            temp[0]=nums[i];
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<n-2;j++)
            {
                temp[1]=nums[j];
                left=j+1;
                right=n-1;
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                while(left<right)
                {
                    long long sum=(long long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target)
                    {
                        temp[2]=nums[left];
                        temp[3]=nums[right];
                        ans.push_back(temp);
                        while(left<right && temp[2]==nums[left])
                        {
                            left++;
                        }
                        while(left<right && temp[3]==nums[right])
                        {
                            right--;
                        }
                    }
                    else if(sum<target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};