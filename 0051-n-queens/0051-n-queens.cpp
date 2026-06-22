class Solution {
public:
    void ways(string s,int row,int col,int n,vector<vector<string>>&ans,vector<vector<int>>&blocked,vector<bool>&bcol,vector<string>temp)
    {
        if(temp.size()==n)
        {
           ans.push_back(temp);
           return;
        }
        for(int i=0;i<n;i++)
        {
           if(bcol[i]==0&&blocked[row][i]==0)
           {
            s[i]='Q'; 
            temp.push_back(s);
            s[i]='.';
            bcol[i]=1;
            int j=row,k=i;
            while(k<n&&k>=0&&j<n)
            {
                blocked[j][k]++;
                j++;
                k++;
            }
            j=row;
            k=i;
            while(k<n&&k>=0&&j<n)
            {
                blocked[j][k]++;
                j++;
                k--;
            }
            
            ways(s,row+1,col,n,ans,blocked,bcol,temp);
            bcol[i]=0;
            j=row;
            k=i;
            while(k<n&&k>=0&&j<n)
            {
                blocked[j][k]--;
                j++;
                k++;
            }
            j=row;
            k=i;
            while(k<n&&k>=0&&j<n)
            {
                blocked[j][k]--;
                j++;
                k--;
            }
           temp.pop_back();
           }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        string s;
        vector<vector<string>>ans;
        vector<string>temp;
        for(int i=0;i<n;i++)
        {
            s+='.';
        }
        vector<bool>bcol(n,0);
        vector<vector<int>>blocked(n,vector<int>(n,0));
        ways(s,0,0,n,ans,blocked,bcol,temp);
        return ans;
    }
};