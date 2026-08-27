class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n=asteroids.size();
        for(int i=0;i<n;i++)
        {
            if(asteroids[i]<0)
            {
                while(!st.empty()&&asteroids[st.top()]>0&&asteroids[st.top()]<abs(asteroids[i]))
                {
                    st.pop();
                }
                if(st.empty()||asteroids[st.top()]<0)
                {
                    st.push(i);
                }
                if(asteroids[st.top()]==abs(asteroids[i]))
                st.pop();
            }    
            else
            st.push(i);
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(asteroids[st.top()]);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};