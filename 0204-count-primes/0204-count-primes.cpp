class Solution {
public:
    int countPrimes(int n) {
        vector<int>prime(n,1);
        if(n<=1)
        {
            return 0;
        }
        prime[0]=0;
        prime[1]=0;
        int ans=n-2;
        for(int i=2;i<n;i++)
        {
            if(prime[i])
            for(long long j=(long long)i*i;j<n;j+=i)
            {
                if (prime[j]) 
                {
                    prime[j] = 0;
                    ans--;
                }
            }
        }
        return ans;
    }
};