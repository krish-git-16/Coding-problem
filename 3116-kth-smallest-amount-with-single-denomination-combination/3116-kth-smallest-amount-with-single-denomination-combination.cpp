class Solution {
public:
    long long count(long long n,vector<int>&coins)
    {
        long long order=0,lcm=0;
        long long ans=0;
        for(long long i=1;i<(1<<coins.size());i++)
        {
            order=0;
            lcm=0;
            for(int j=0;j<coins.size();j++)
            {
                if(i&(1<<j))
                {
                    if(lcm==0)
                    {
                        lcm=coins[j];
                    }
                    else
                    {
                        lcm=lcm/gcd(lcm,coins[j])*coins[j];
                    }
                    order++;
                }
            }
            if(order%2==0)
            {
                ans-=n/lcm;
            }
            else
            {
                ans+=n/lcm;
            }
        }
        return ans;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long end=1ll*k*(*max_element(coins.begin(),coins.end())),start=0;
        int n=coins.size();
        long long ans=0;
        while(start<=end)
        {
            long long mid=start+(end-start)/2;
            if(k<=count(mid,coins))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
};