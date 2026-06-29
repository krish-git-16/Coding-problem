class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans(rowIndex+1,1);
        vector<int>prev(rowIndex+1,1);
        int f=0,l=rowIndex;
        for(int i=1;i<=rowIndex;i++)
        {
            for(int j=1;j<i;j++)
            {
                ans[j]=prev[j-1]+prev[j];
            }
            prev=ans;
        }
        return ans;
    }
};