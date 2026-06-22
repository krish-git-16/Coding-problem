class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        int start=0,end=0,mid,sum=0,co,ans=0;
       
        for(int k=0;k<arr.size();k++)
        {
            start=max(start,arr[k]);
            end+=arr[k];
        }

        while(start<=end)
        {
            mid=start+(end-start)/2;
            co=1;
            sum=0;
            for(int i=0;i<arr.size();i++)
            {
               sum+=arr[i];
               if(sum>mid)
               {
                sum=arr[i];
                co++;
               }   
            }
            if(co<=k)
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