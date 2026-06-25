class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int first=0,second=1;
        int n=nums.size();
        while(second<n)
        {
            if(nums[first]!=nums[second])
            {
                first++;
                nums[first]=nums[second];
            }
            second++;
        }
        return first+1;
        
        
    }
};