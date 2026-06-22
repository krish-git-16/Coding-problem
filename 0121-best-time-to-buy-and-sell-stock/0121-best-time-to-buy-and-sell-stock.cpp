class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int buy=arr[0],profit=0,max=0;
        for(int i=1;i<arr.size();i++)
        {
            if(buy>arr[i])
            {
                buy=arr[i];
            }
            else
            {
                profit=arr[i]-buy;
            }
            if(profit>max)
            {
                max=profit;
            }
        }
        return max;
    }
};