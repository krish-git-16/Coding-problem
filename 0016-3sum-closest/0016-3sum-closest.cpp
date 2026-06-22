class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int first=1,last=nums.size()-1;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int temp=INT_MAX,ans=0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                first=j+1;
                last=n-1;
                while(first<=last)
                {
                    int mid=first+(last-first)/2;
                    if(nums[i]+nums[j]+nums[mid]==target)
                    {
                        return target;
                    }
                    else if(nums[i]+nums[j]+nums[mid]<target)
                    {
                        if(abs(target-(nums[i]+nums[j]+nums[mid]))<temp)
                        {
                            temp=min(temp,abs(target-(nums[i]+nums[j]+nums[mid])));
                            ans=nums[i]+nums[j]+nums[mid];
                        }    
                        first=mid+1;
                    }
                    else
                    {
                        if(abs(target-(nums[i]+nums[j]+nums[mid]))<temp)
                        {
                            temp=min(temp,abs(target-(nums[i]+nums[j]+nums[mid])));
                            ans=nums[i]+nums[j]+nums[mid];
                        }
                        last=mid-1;
                    }
                }
            }
        }
        return ans;
    }
};