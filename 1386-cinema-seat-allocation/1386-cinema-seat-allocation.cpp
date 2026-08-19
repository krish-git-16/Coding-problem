class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<reservedSeats.size();i++)
        {
            int f=reservedSeats[i][0];
            int s=reservedSeats[i][1];
            if(adj.find(f) == adj.end())
            adj[f] = vector<int>(10, 1);
            adj[f][s-1]=0;
        }
        int ans = 2 * (n - adj.size());
        for(auto &row : adj)
        {
            bool left = true;
            bool middle = true;
            bool right = true;

            for(int i=1;i<5;i++)
            {
                if(!row.second[i])
                {
                    left=0;
                }
            }
            for(int i=3;i<7;i++)
            {
                if(!row.second[i])
                {
                    middle=0;
                }
            }
            
            for(int i=5;i<9;i++)
            {
                if(!row.second[i])
                {
                    right=0;
                }
            }
            if(left&&right)
            {
                ans+=2;
            }
            else if(left||middle||right)
            {
                ans+=1;
            }
        }
        return ans;
    }
};