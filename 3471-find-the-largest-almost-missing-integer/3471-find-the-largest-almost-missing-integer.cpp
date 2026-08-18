class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int last=nums[n-1],first=nums[0];
        bool ff=0,fl=0;
        if(n==0)
        return -1;
        if(k==1)
        {
            unordered_map<int,int>m;
            for(int i=0;i<n;i++)
            {
                m[nums[i]]++;
            }
            int ans=-1;
            for(int i=0;i<n;i++)
            {
                if(m[nums[i]]==1)
                {
                    ans=max(ans,nums[i]);
                }
            }
            return ans;
        }
        else if(k==n)
        return *max_element(nums.begin(),nums.end());
        else
        {
            if(first==last)
            return -1;
            for(int i=1;i<n-1;i++)
            {
                if(last==nums[i])
                fl=1;
                if(first==nums[i])
                ff=1;
            }
            if(!ff&&!fl)
            return max(first,last);
            if(!ff)
            return first;
            if(!fl)
            return last;
            return -1;
        }    
    }
};