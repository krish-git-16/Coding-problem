class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        for(auto &f : flights)
        {
            adj[f[0]].push_back({f[1],f[2]});
        }
        pq.push({0,{src,0}});
        while(!pq.empty())
        {
            int d=pq.top().first;
            int u=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(j>k+1)
            {
                continue;
            }
            if(u==dst)
            return d;
            
            for(int i=0;i<adj[u].size();i++)
            {
                int v=adj[u][i].first;
                int w=adj[u][i].second;
                if(j + 1 <= k + 1 && d + w < dist[v][j + 1])
                {
                    dist[v][j + 1] = d + w;
                    pq.push({d+w,{v,j+1}});
                }    
            }
        }
        return -1;
    }
};