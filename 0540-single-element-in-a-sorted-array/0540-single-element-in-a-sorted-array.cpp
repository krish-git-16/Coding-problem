class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0,end=nums.size()-1,n=nums.size(),ans=0;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(mid+1<n&&nums[mid]==nums[mid+1]&&mid%2==1)
            {
                end=mid-1;
            }
            else if(mid+1<n&&nums[mid]==nums[mid+1]&&mid%2==0)
            {
                start=mid+1;
            }
            else if(mid+1<n&&nums[mid]!=nums[mid+1]&&mid%2==1)
            {
                start=mid+1;
            }
            else
            {
                ans=mid;
                end=mid-1;
            }
        }
        return nums[ans];
    }
};