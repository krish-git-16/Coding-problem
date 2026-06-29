class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                indeg[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(!indeg[i])
            {
                q.push(i);
            }
        }
        vector<int>ans;
        int l=0;
        while(!q.empty())
        {
            int first=q.front();
            q.pop();
            for(int i=0;i<adj[first].size();i++)
            {
                indeg[adj[first][i]]--;
                if(indeg[adj[first][i]]==0)
                {
                    q.push(adj[first][i]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(indeg[i])
            {
                return 0;
            }
        }
        return 1;
        
    }
};