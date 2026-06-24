class Solution {
public:
    int trap(vector<int>& arr) {
        int sum=0,prefix=arr[0],a=0;
        vector<int> n(arr.size());
        for(int j=arr.size()-1;j>=0;j--)
        {
            a=max(a,arr[j]);
            n[j]=a;
        }
        for(int i=1;i<arr.size()-1;i++)
        {            
            if(prefix>n[i+1])
                {
                    prefix=n[i+1];
                }
            if(prefix>=arr[i])
            {
                sum+=prefix-arr[i];                
            }
            else 
            {
                prefix=arr[i];
                
            }
        }
        return sum;
    }
};