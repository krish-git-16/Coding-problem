class Solution {
public:
    int smallestNumber(int n, int t) {
        
        for(int i=n;i<INT_MAX;i++)
        {
            int mul=1;
            int num=i;
            while(num)
            {
                int rem=num%10;
                num/=10;
                mul*=rem;
            }
            if(mul%t==0)
            {
                return i;
            }
        }
        return 0;
    }
};