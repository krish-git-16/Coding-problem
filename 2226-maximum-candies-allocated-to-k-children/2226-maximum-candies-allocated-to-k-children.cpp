class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low=1,high=*max_element(candies.begin(),candies.end());
        long long ans=0,stu;
        while(low<=high)
        {
            stu=0;
            long long mid=low+(high-low)/2;
            for(int i=0;i<candies.size();i++)
            {
                stu+=candies[i]/mid;
            }
            if(stu>=k)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};