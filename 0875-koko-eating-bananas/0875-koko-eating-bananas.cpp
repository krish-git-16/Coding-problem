class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int days) {
      int start=1,end=0,mid,ans;
      long int count;
       
        for(int j=0;j<arr.size();j++)
        {
            end=max(end,arr[j]);
        }
         if(arr.size()==days)
        {
            return end;
        }
        while(start<=end)
        {
            mid=start+(end-start)/2;
            count=0;
            if (mid==0)
            {
                return 1;
            }
            for(int i=0;i<arr.size();i++)
            {
            
                if(arr[i]%mid==0)
                {
                    count+=arr[i]/mid;
                }
                else
                     count+=(arr[i]/mid)+1;
            }
            if(count<=days)
            {
                ans=mid;
                end=mid-1;
            }
            else if(count>days)
            {
                start=mid+1;
            }
           
        }
        return ans;
  
    }
};