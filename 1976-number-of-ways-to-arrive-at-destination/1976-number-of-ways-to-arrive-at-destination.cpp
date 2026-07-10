class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        int dest=n-1;
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long>dis(n,LLONG_MAX);
        vector<int>ways(n,0);
        ways[0]=1;
        dis[0]=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            int node=pq.top().second;
            long long d=pq.top().first;
            pq.pop();
            if(d > dis[node])
            continue;
            for(auto it:adj[node])
            {
                int v=it.first;
                int w=it.second;
                if(w+d==dis[v])
                {
                    ways[v]=(ways[v]+ways[node])%1000000007;
                }
                else if(w+d<dis[v])
                {
                    dis[v]=w+d;
                    ways[v]=ways[node];
                    pq.push({w+d,v});
                }
            }
        }
        return ways[n-1];
    }
};