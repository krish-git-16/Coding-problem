class Solution {
public:
    int f(vector<int>& arr,int k,int i,vector<int>&dp)
    {
        if(i==arr.size())
        return 0;
        int sum=INT_MIN;
        int num=arr[i];
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        for(int v=i;v<min((int)arr.size(), i+k);v++)
        {
            num=max(num,arr[v]);
            int pcost=num*(v-i+1)+f(arr,k,v+1,dp);
            sum=max(sum,pcost);
        }
        return dp[i]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return f(arr,k,0,dp);
    }
};