class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n=drones.size();
        int mini=INT_MAX,idx=-1;
        for(int i=0;i<n;i++)
        {
            int x=drones[i][0];
            int y=drones[i][1];
            int r=drones[i][2];
            if(abs(target[0]-x)+abs(target[1]-y)<=r)
            {
                if(abs(target[0]-x)+abs(target[1]-y)<mini)
                {
                    mini=abs(target[0]-x)+abs(target[1]-y);
                    idx=i;
                }
            }
        }
        return idx;
    }
};