class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0,end=nums.size();
        int index=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(mid+1<nums.size()&&mid-1>=0&&nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1])
            {
                index = mid;
                return mid;
            }
            else if(mid+1<nums.size()&&nums[mid]<nums[mid+1])
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(mid+1<nums.size()&&mid-1>=0&&nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1])
            {
                index = mid;
                return mid;
            }
            else if(mid+1<nums.size()&&nums[mid]<nums[mid+1])
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        if(index==-1)
        {
            if(nums[0]>nums[nums.size()-1])
            return 0;
            return nums.size()-1;
        }
        return index;
    }
};