class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first=0,second=0;
        while(second<nums.size())
        {
            if(nums[second])
            {
                nums[first]=nums[second];
                first++;
            }
            second++;
        }
        while(first<nums.size())
        {
            nums[first++]=0;
        }
    }
};