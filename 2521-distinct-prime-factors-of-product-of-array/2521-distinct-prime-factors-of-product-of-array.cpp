class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        vector<int>prime(n+1,1);
        for (int i = 0; i <= n; i++)
        prime[i] = i;
        for(int i=2;i<=n;i++)
        {
            if(prime[i]==i)
            for(long long j=(long long)i*i;j<=n;j+=i)
            {
                if(prime[j]==j)
                prime[j]=i;
            }
        }
        set<int>m;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int x = nums[i];
            while (x > 1) {
                m.insert(prime[x]);
                x /= prime[x];
            }
        }
        for(auto it:m)
        {
            ans++;
        }
        return ans;
    }
};