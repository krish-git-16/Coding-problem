class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ind=0,n=nums.size();
        while(ind<n)
        {
            if(ind==n-1)
            return 1;
            int m=-1,ind1=ind;
            for(int i=ind+1;i<=ind+nums[ind]&&i<n;i++)
            {
                if(m<i+nums[i])
                {
                    m=i+nums[i];
                    ind1=i;
                }
            }
            if(ind==ind1)
            return 0;
            ind=ind1;
        }
        return 1;
    }
};