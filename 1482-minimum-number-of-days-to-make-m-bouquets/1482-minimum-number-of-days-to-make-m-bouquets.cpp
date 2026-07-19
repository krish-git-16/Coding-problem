class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxdays=*max_element(bloomDay.begin(),bloomDay.end());
        int start=0,end=maxdays,ans=-1,n=bloomDay.size();
        if(n<(long long)k*m)
        {
            return -1;
        }
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int temp=0,b=0;
            for(int i=0;i<n;i++)
            {
                if(bloomDay[i]<=mid)
                {
                    temp++;
                    if(temp==k)
                    {
                        b++;
                        temp=0;
                    }
                }
                else
                {
                    temp=0;
                }
                
            }
            if(b>=m)
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