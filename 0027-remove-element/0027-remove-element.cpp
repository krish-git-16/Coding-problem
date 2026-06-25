class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int second=n-1,first=0;
        while(first<=second)
        {
            if(nums[first]==val)
            {
                swap(nums[first],nums[second]);
                second--;
            }
            else
            {
                first++;
            }    
        }
        return second+1;
    }
};