class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int>ans(n*m,0);
        int fill=0;
        int top=0,left=0,right=n-1,bottom=m-1;
        while(fill!=(n*m))
        {
            for(int i=left;i<=right;i++)
            {
               ans[fill]=matrix[top][i];
               fill++;
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
               ans[fill]=matrix[i][right];
               fill++;
            }
            right--;
            if (top <= bottom)
            for(int i=right;i>=left;i--)
            {
               ans[fill]=matrix[bottom][i];
               fill++;
            }
            bottom--;
            if (left <= right)
            for(int i=bottom;i>=top;i--)
            {
               ans[fill]=matrix[i][left];
               fill++;
            }
            left++;   
        }
        return ans;
    }
};