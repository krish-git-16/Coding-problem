class Solution {
public:
    // int f(vector<int>& arr,int k,int i,vector<int>&dp)
    // {
    //     if(i==arr.size())
    //     return 0;
        
    //     if(dp[i]!=-1)
    //     {
    //         return dp[i];
    //     }
        
    //     return 
    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(arr.size()+1,0);
        // return f(arr,k,0,dp);
        for (int i = n - 1; i >= 0; i--) {
            int maxi = INT_MIN;
            int best = INT_MIN;
    
            for (int v = i; v < min(n, i + k); v++) {
                maxi = max(maxi, arr[v]);
                int cost = maxi * (v - i + 1) + dp[v + 1];
                best = max(best, cost);
            }
    
            dp[i] = best;
        }
        return dp[0];
    }
};