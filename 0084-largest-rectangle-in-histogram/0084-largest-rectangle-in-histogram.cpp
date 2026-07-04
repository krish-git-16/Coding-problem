class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int>st;
        stack<int>right;
        int area=0,ans=0;
        vector<int>templ(arr.size(),1);
        vector<int>tempr(arr.size(),1);
        //no. of next greater on right
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
            {
                templ[i]+=templ[st.top()];
                st.pop();
            }
            st.push(i);
        }
        //no. of next greater on left
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!right.empty()&&arr[right.top()]>=arr[i])
            {
                tempr[i]+=tempr[right.top()];
                right.pop();
            }
            right.push(i);
        }
        //finding max area 
        for(int i=0;i<arr.size();i++)
        {
            area=arr[i]*(templ[i]+tempr[i]-1);
            if(area>ans)
            {
                ans=area;
            }
        }
        return ans;
    }
};