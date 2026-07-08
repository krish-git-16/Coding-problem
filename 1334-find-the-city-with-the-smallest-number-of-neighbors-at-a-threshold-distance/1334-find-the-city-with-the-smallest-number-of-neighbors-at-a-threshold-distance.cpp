class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>e(n,vector<int>(n,INT_MAX));
        int ans;
        for(int i = 0; i < n; i++)
        e[i][i] = 0;
        for(int i=0;i<edges.size();i++)
        {
            int f=edges[i][0];
            int s=edges[i][1];
            int weight=edges[i][2];
            e[f][s]=weight;
            e[s][f]=weight;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(e[i][k] != INT_MAX && e[k][j] != INT_MAX)
                    e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
                }
            }
        }
        int a=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int t=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j&&e[i][j]<=distanceThreshold)
                {
                    t++;
                }
            }
            if(t<=a)
            {
                a=t;
                ans=i;
            }
        }
        return ans;
    }
};