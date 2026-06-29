class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            if(st.count(nums[i]))
            {
                return 1;
            }
            st.insert(nums[i]);
        }
        return 0;
    }
};