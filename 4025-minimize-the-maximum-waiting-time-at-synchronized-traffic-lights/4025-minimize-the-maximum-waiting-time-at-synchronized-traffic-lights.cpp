class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        sort(lights.begin(),lights.end());
        sort(arrivalTime.begin(),arrivalTime.end());
        int start,end,r;
        int ans=0;
        for(int i=0;i<arrivalTime.size();i++)
        {
            r=arrivalTime[i]%period;
            if(r>=lights[lights.size()-1])
            {
                ans=max(ans,period-r);
            }
        }
        return ans;
    }
};