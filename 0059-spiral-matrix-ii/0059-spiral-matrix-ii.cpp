class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,1));
        int fill=1;
        int top=0,left=0,right=n-1,bottom=n-1;
        while(fill!=(n*n)+1)
        {
            for(int i=left;i<=right;i++)
            {
               ans[top][i]=fill;
               fill++;
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
               ans[i][right]=fill;
               fill++;
            }
            right--;
            for(int i=right;i>=left;i--)
            {
               ans[bottom][i]=fill;
               fill++;
            }
            bottom--;
            for(int i=bottom;i>=top;i--)
            {
               ans[i][left]=fill;
               fill++;
            }
            left++;   
        }
        return ans;
    }
};