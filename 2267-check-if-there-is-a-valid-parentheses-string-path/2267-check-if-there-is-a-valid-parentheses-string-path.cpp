class Solution {
public:
    int row[2]={1,0};
    int col[2]={0,1};
    bool hasValidPath(vector<vector<char>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size(),m=grid[0].size();
        if ((n + m - 1) % 2 != 0)
        return false;
        q.push({0,{0,1}});
        vector<vector<vector<bool>>> visited(
            n, vector<vector<bool>>(m, vector<bool>(n+m, false))
        );
        if (grid[0][0] != '(')
        return false;
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second.first;
            int valid=q.front().second.second;
            q.pop();
            if (valid < 0)
            continue;
            if(i==n-1&&j==m-1&&valid==0)
            {
                return true;
            }
            for(int k=0;k<2;k++)
            {
                int ni=i+row[k];
                int nj=j+col[k];

                if(ni<n && nj<m) 
                { 
                    int newValid = valid;

                    if(grid[ni][nj]=='(') 
                    { 
                        newValid++;
                    }     
                    else 
                    { 
                        if(valid==0)
                            continue;

                        newValid--;
                    }

                    if(!visited[ni][nj][newValid])
                    {
                        visited[ni][nj][newValid] = true;
                        q.push({ni,{nj,newValid}});
                    }
                } 
            }
            
        }
        return false;
    }
};