class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int f=0,l=cardPoints.size()-1;
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=cardPoints[i];
        }
        f=k-1;
        int ans=sum;
        for(int i=0;i<k;i++)
        {
            sum+=cardPoints[l]-cardPoints[f];
            f--;
            l--;
            ans=max(sum,ans);
        }
        return ans;
    }
};