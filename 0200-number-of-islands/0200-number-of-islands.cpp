class Solution {
public:
    int row[4]={0,0,1,-1};
    int col[4]={1,-1,0,0};
    bool valid(int r,int c,int m,int n)
    {
        return r>=0&&c>=0&&c<n&&r<m;
    }
    void bfs(vector<vector<int>> &vis,vector<vector<char>>& grid,int i,int j)
    {
            int m=grid.size(), n=grid[0].size();
            queue<pair<int,int>> q;
            q.push({i,j});
            vis[i][j] = true;
            while(!q.empty())
            {
                auto node = q.front();
                q.pop();
                int i=node.first;
                int j=node.second;
                vis[i][j]=1;
                for(int k=0;k<4;k++)
                {
                    if(valid(i+row[k],j+col[k],m,n)&&!vis[i+row[k]][j+col[k]]&&grid[i+row[k]][j+col[k]]=='1')
                    {
                        vis[i+row[k]][j+col[k]]=1;
                        q.push({i+row[k],j+col[k]});
                    }
                }
            }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(m,vector<int>(n,0));    
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j]&&grid[i][j]=='1')
                {
                    bfs(vis,grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};