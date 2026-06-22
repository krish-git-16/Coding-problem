class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int start=0,end=arr.size()-1,count=0,mid;
        while(start<=end )
        {
            mid=start+(end-start)/2;
            if(arr[mid]>=arr[mid+1] && arr[mid]>=arr[mid-1])
            {
                count=mid;
                break;
            }
            else if(arr[mid]<arr[mid+1])
            {
                start=mid+1;
            }
            else if(arr[mid]<arr[mid-1])
            {
                end=mid-1;
            }
        }
         return count;
    }
};