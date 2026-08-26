class Solution {
public:
    void s1(vector<int>&nse,vector<int>&nums)
    {
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty()&&nums[st.top()]>=nums[i])
            st.pop();
            nse[i]=st.empty()?nums.size():st.top();
            
            st.push(i);
        }
    }
    void s2(vector<int>&nse,vector<int>&nums)
    {
        stack<int>st;
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty()&&nums[st.top()]>nums[i])
            st.pop();
            nse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
    }
    void s3(vector<int>&nse,vector<int>&nums)
    {
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty()&&nums[st.top()]<=nums[i])
            st.pop();
            nse[i]=st.empty()?nums.size():st.top();
            
            st.push(i);
        }
    }
    void s4(vector<int>&nse,vector<int>&nums)
    {
        stack<int>st;
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty()&&nums[st.top()]<nums[i])
            st.pop();
            nse[i]=st.empty()?-1:st.top();
            
            st.push(i);
        }
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>nse(n,0);
        vector<int>psee(n,0);
        vector<int>nge(n,0);
        vector<int>pgee(n,0);
        s1(nse,nums);
        s2(psee,nums);
        s3(nge,nums);
        s4(pgee,nums);
        long long total1=0,total2=0,left,right,mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            right=nse[i]-i;
            left=i-psee[i];
            total1=(total1+(left*right*1ll*nums[i]));
        }
        for(int i=0;i<n;i++)
        {
            right=nge[i]-i;
            left=i-pgee[i];
            total2=(total2+(left*right*1ll*nums[i]));
        }
        return total2-total1;
    }
};