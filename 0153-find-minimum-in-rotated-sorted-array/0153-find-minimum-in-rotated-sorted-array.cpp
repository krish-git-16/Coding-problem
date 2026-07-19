class Solution {
public:
    int findMin(vector<int>& arr) {
        int start=0,end=arr.size()-1,count=0,mid,a=arr[0];
        while(start<=end )
        {
            mid=start+(end-start)/2;
            if( arr[mid]<a )
            {
                a=arr[mid];
                count=mid;
                end=mid-1;
            }
            else if(arr[mid]>=a)
            {
                start=mid+1;
            }   
        }
        return arr[count];
    }
};