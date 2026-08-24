class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int n=intervals.size();
        int i=0;
        vector<vector<int>>ans;
        while(i<n&&intervals[i][1]<newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        int low,high;
        low=newInterval[0];
        high=newInterval[1];
        while(i<n&&intervals[i][1]>=newInterval[0]&&intervals[i][0]<=newInterval[1])
        {
            low=min(intervals[i][0],low);
            high=max(intervals[i][1],high);
            i++;
        }
        ans.push_back({low,high});
        while(i<n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};