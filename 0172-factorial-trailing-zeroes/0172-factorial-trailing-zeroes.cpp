class Solution {
public:
    int trailingZeroes(int n) {
        int count=0,num=n;
        if(n==0)
        {
            return 0;
        }
        while(num)
        {
           num/=5;
           count+=num;
        }
        return count;
    }
};