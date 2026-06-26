class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int i=1;
        int j=0;
        ans.push_back({intervals[0][0],intervals[0][1]});
        while(i<intervals.size())
        {
            vector<int>temp(2);
            if(ans[j][1]>=intervals[i][0])
            {
                if(ans[j][1]<intervals[i][1])
                {
                    ans[j][1]=intervals[i][1];
                }
                i++;
            }
            else
            {
                ans.push_back({intervals[i][0],intervals[i][1]});
                i++;
                j++;
            }
        }
        return ans;
    }
};