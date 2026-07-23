class Solution {
public:
    bool checkPerfectNumber(int n) {
        int ans=0;
        if(n==1)
        return 0;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            ans+=i;
            int N=n/i;
            if(N!=i&&N!=n&&n%N==0)
            ans+=N;
        }
        return ans==n;
    }
};