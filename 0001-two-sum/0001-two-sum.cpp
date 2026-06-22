class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> copy(nums.size());
       for(int i=0;i<nums.size();i++)
       {
        copy[i]=nums[i];
       }
       sort(nums.begin(),nums.end());
       int i=0,j=nums.size()-1,sum,a,b,c;
       vector<int>n;
       while(i<j)
       {
          sum=nums[i]+nums[j];
          if(sum==target)
          {
            a=nums[i];
            b=nums[j];
            break;
          }
          else if(sum>target)
          {
            j--;
          }
          else
          {
            i++;
          }
       } 
       for(int i=0;i<nums.size();i++)
       {
         if(a==copy[i])
         {
            n.push_back(i);
            c=i;
            break;
         }
         
       }
       for(int i=0;i<nums.size();i++)
       {
         if(b==copy[i] && c!=i)
         {
            n.push_back(i);
            break;
         }
         
       }
       return n;
    }
};